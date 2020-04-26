#include <KNotification>
#include <QAction>

#include "timer.h"

Timer::Timer()
    : QObject()
{
    connect(&timer, &QTimer::timeout, this, &Timer::timerFinished);
}

void Timer::timerFinished()
{
    //const static QString defaultTitle = QStringLiteral("Timer finished!");
    const static QString defaultEvent = QStringLiteral("done");
    const static QString remindLater = QStringLiteral("Remind me in 5 minutes");
    auto *notification = KNotification::event(defaultEvent, QString(), name, QString(), nullptr,
                                              KNotification::Persistent, "krunner_timer");
    notification->setActions({defaultEvent, remindLater});

    connect(notification, &KNotification::action1Activated, this, &Timer::markAsDone);
    connect(notification, &KNotification::action2Activated, this, &Timer::remindLater);

    timer.stop();
}

void Timer::remindLater()
{
    timer.start(5 * 60 * 1000);
    done = false;
}

void Timer::markAsDone()
{
    done = true;
    Q_EMIT isDone();
}
