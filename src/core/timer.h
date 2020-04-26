#ifndef TIMER_H
#define TIMER_H

#include "QtCore"

class Timer: public QObject{
Q_OBJECT
    
public:
    explicit Timer();
    QString name;
    QTimer timer;
    //
    bool isDuration = false;
    QString initialUnit;
    int initialValue = -1;
    QTime initialTime;
    bool done = false;
    QTime overdueTime;

public Q_SLOTS:
    void timerFinished();
    void remindLater();
    void cancel();
    void markAsDone();

Q_SIGNALS:
    void isDone();
};
#endif
