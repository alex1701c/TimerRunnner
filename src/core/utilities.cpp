#include "utilities.h"

#include <QtCore>
#include <KNotification>

int Utilities::timeUnitToMSec(const QString &unit, int time)
{
    const static QStringList seconds = {"s", "sec", "seconds"};
    const static QStringList minutes = {"m", "min", "minutes"};
    const static QStringList hours = {"h", "hours"};
    if (seconds.contains(unit)) {
        return time * 1000;
    }
    if (minutes.contains(unit)) {
        return time * 1000 * 60;
    }
    if (hours.contains(unit)) {
        return time * 1000 * 60 * 60;
    }
    return -1;
}

// If the current unit is >= 1, display it, then pass call function again
// but set recrusive to false
#define conversionCall(value, singular, plural) \
  if (msec >= value) { \
float units = (float) msec / value; \
float _fullUnit; \
float remainingMsec; \
remainingMsec = (std::modf(units, &_fullUnit)); \
 \
QString text; \
if (static_cast<int>(units) > 1) { \
text = QString::number(static_cast<int>(units)) + ' ' + plural; \
} else { \
text = QStringLiteral("1 ") + singular; \
} \
if (recrusive) {\
return text + ' ' + msecToTime(remainingMsec * value, false); \
} \
return text; \
} \

QString Utilities::msecToTime(int msec, bool recrusive)
{
    conversionCall((60 * 60 * 1000), "hour", "hours")
    conversionCall((60 * 1000), "minute", "minutes")
    conversionCall((1000), "second", "seconds")

    return QString();
}
void Utilities::showErrorNotification(const QString &msg)
{
    KNotification::event(QStringLiteral("error"), msg,
                         QString(), QString(), nullptr,
                         KNotification::CloseOnTimeout, "krunner_timer");
}
