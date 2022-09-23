#include "Logger.hpp"

#include <QDateTime>
#include <sstream>

#include <android/log.h>


void Logger::logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    s_mutex.lock();

    std::ostringstream buf;

    android_LogPriority priority = ANDROID_LOG_DEBUG;

    switch (type)
    {
        case QtDebugMsg:
            buf << "D [";
            priority = ANDROID_LOG_DEBUG;
            break;
        case QtWarningMsg:
            buf << "W [";
            priority = ANDROID_LOG_WARN;
            break;
        case QtInfoMsg:
            buf << "I [";
            priority = ANDROID_LOG_INFO;
            break;
        case QtCriticalMsg:
            buf << "C [";
            priority = ANDROID_LOG_ERROR;
            break;
        case QtFatalMsg:
            buf << "F [";
            priority = ANDROID_LOG_FATAL;
            break;
        default:
            buf << "U [";
            break;
    }

    buf << QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddTHH:mm:ss.zzz").toStdString() << "] ";

    if (context.file)
    {
        const std::string filename(context.file);
        size_t lastSlash = filename.find_last_of('/');
        if (lastSlash == std::string::npos)
            lastSlash = 0;
        else
            lastSlash += 1;
        buf << '(' << filename.substr(lastSlash) << ':' << context.line << ") ";
    }
    else if (context.function)
    {
        buf << '(' << context.function << ") ";
    }

    buf << msg.toStdString() << "\n";

    const std::string data = buf.str();

#ifdef LOG_TO_FILE

    if (s_writeToFileAllowed)
    {
        s_logFile.open(QIODevice::WriteOnly | QIODevice::Append);

        s_logFile.write(data.c_str());

        s_logFile.close();
    }

#endif

    __android_log_write(priority, "FDC", data.c_str());

    s_mutex.unlock();
}
