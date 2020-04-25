#include <KNotification>

#include "timer.h"

Timer::Timer()
    : QObject()
{
    connect(&timer, &QTimer::timeout, this, &Timer::timerFinished);
}

void Timer::timerFinished()
{
    KNotification::event(KNotification::Notification, "Timer finished!", name);
    timer.stop();
}
