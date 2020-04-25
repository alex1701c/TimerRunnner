//  Licensed under the GNU LESSER GENERAL PUBLIC LICENSE Version 2.1. See License in the project root for license information.
#include "timerrunner.h"

#include <QDBusConnection>
#include <QDBusArgument>
#include <QDBusMetaType>
#include <QDebug>
#include <iostream>

// Generated by qt5_add_dbus_adaptor command im CMakeLists.txt file
#include "krunner1adaptor.h"

TimerRunner::TimerRunner() {
    new Krunner1Adaptor(this);
    qDBusRegisterMetaType<RemoteMatch>();
    qDBusRegisterMetaType<RemoteMatches>();
    qDBusRegisterMetaType<RemoteAction>();
    qDBusRegisterMetaType<RemoteActions>();
    QDBusConnection::sessionBus().registerService(QStringLiteral("net.timerrunner2"));
    QDBusConnection::sessionBus().registerObject(QStringLiteral("/timerrunner"), this);
}

RemoteMatches TimerRunner::Match(const QString &searchTerm) {
    if (!searchTerm.startsWith(triggerWord)) {
        return {};
    }
    RemoteMatches ms;
    bool exactMatch = false;
    for (const auto *timer: qAsConst(timers)) {
        if (timer->name.contains(searchTerm, Qt::CaseInsensitive)) {
            if (!exactMatch) {
                exactMatch = timer->name.compare(searchTerm, Qt::CaseInsensitive) == 0;
            }
            RemoteMatch m;
            m.id = timer->name;
            m.text = QStringLiteral("%1 %2").arg(timer->name, timer->timer.remainingTime());
            m.iconName = QStringLiteral("planetkde");
            m.type = Plasma::QueryMatch::ExactMatch;
            m.relevance = 0.8;
            ms.append(m);
        }
    }
    
    RemoteMatch m;
    m.id = "new";
    m.text = "New Timer";
    m.iconName = QStringLiteral("org.kde.plasma.timer");
    m.type = Plasma::QueryMatch::ExactMatch;
    m.relevance = 0.8;
    ms.append(m);
    return ms;

}

RemoteActions TimerRunner::Actions() {
    return RemoteActions();
}

void TimerRunner::Run(const QString &id, const QString &actionId) {
    if (id == QLatin1String("new")) {
        auto *t = new Timer();
        t->timer.start(10*1000);
        timers.append(t);
    }
}
