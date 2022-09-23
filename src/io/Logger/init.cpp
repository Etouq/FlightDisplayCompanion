#include "Logger.hpp"

#ifdef LOG_TO_FILE
#include <QStandardPaths>
#include <QDateTime>
#include <QtAndroid>
#endif

void Logger::init()
{
#ifdef LOG_TO_FILE

    s_writeToFileAllowed = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE") == QtAndroid::PermissionResult::Granted;

    if (!s_writeToFileAllowed)
        return;

    s_logFile.setFileName(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/fdc_log.txt");
    bool fileAlreadyExists = s_logFile.exists();
    s_logFile.open(QIODevice::WriteOnly | QIODevice::Append);

    std::string data = "";

    if (fileAlreadyExists)
        data += "\n\n\n\n\n\n\n\n\n\n";

    data += "[" + QDateTime::currentDateTimeUtc().toString("yyyy-MM-ddTHH:mm:ss.zzz").toStdString() + "]: Start of new log\n\n";

    s_logFile.write(data.c_str());

    s_logFile.close();

#endif
}