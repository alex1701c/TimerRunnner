#ifndef TIMER_H
#define TIMER_H

#include "QtCore"

class Timer: public QObject{
Q_OBJECT
    
public:
    explicit Timer();
    QString name;
    QTimer timer;
    
public Q_SLOTS:
    void timerFinished();
};
#endif
