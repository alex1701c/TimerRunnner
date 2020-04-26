//  Licensed under the GNU LESSER GENERAL PUBLIC LICENSE Version 2.1. See License in the project root for license information.
#pragma once

#include <QtCore>
#include "core/timer.h"
#include "dbus_utils.h"

class TimerRunner: public QObject
{
Q_OBJECT

public:
    explicit TimerRunner();
    QLatin1String triggerWord = QLatin1String("timer");
    QRegularExpression timerQueryRegex;
    QRegularExpression timerTimeQueryRegex;
    QString iconName = QStringLiteral("org.kde.plasma.timer");
    QList<Timer *> timers;

    // Some default values
    const int defaultValue = 5;
    const QString  defaultUnit = QStringLiteral("min");

    RemoteMatches displayTimers(const QString &searchTerm);
    RemoteMatch getDurationRemoteMatch(const QRegularExpressionMatch &match);
    RemoteMatch getTimeRemoteMatch(const QRegularExpressionMatch &match);

public Q_SLOTS:
    RemoteActions Actions();
    RemoteMatches Match(const QString &searchTerm);
    void Run(const QString &id, const QString &actionId);
    void removeTimer();
};
