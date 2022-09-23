#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <QFile>
#include <QMutex>
#include <QObject>

class Logger : public QObject
{
    Q_OBJECT

public:

    static void init();

    static void logOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg);

private:

    Logger() = delete;

    inline static QFile s_logFile;

    inline static QMutex s_mutex;

    inline static bool s_writeToFileAllowed = false;
};

#endif  // __LOGGER_HPP__
