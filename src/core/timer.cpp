#include <KNotification>
#include <QAction>

#include "timer.h"
#include "utilities.h"

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
void Timer::cancel()
{
    const static QString cancelEvent = QStringLiteral("cancel");
    const static QString cancelTitle = QStringLiteral("Timer Canceled");
    const static QString cancelText = QStringLiteral("The timer \"%1\" has been canceled\n%2 before it ended");
    KNotification::event(cancelEvent, cancelTitle,
                         cancelText.arg(name, Utilities::msecToTime(timer.remainingTime())),
                         QString(), nullptr, KNotification::CloseOnTimeout, "krunner_timer");
    timer.stop();
    markAsDone();
}

