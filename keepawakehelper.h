#ifndef KEEPAWAKEHELPER_H
#define KEEPAWAKEHELPER_H

#include <QAndroidJniObject>

class KeepAwakeHelper
{
public:
    KeepAwakeHelper();
    virtual ~KeepAwakeHelper();

private:
    QAndroidJniObject m_wakeLock;
};

#endif // KEEPAWAKEHELPER_H
