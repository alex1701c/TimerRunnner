#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>

class Utilities
{
public:
    static int timeUnitToMSec(const QString &unit, int time);
    static QString msecToTime(int msec, bool recrusive = true);
};


#endif //UTILITIES_H
