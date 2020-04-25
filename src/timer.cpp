#include <KNotification>

#include "timer.h"

Timer::Timer()
    : QObject()
{
    connect(&timer, &QTimer::timeout, this, &Timer::timerFinished);
}

void Timer::timerFinished()
{
    const static QString defaultTitle = QStringLiteral("Timer finished!");
    const static QString defaultEvent = QStringLiteral("done");
    KNotification::event(defaultEvent, defaultTitle, name, QString(), nullptr,
                         KNotification::CloseOnTimeout, "krunner_timer");
    timer.stop();
    done = true;
}
