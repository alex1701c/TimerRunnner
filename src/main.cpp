#include <QCoreApplication>
#include "timerrunner.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    TimerRunner r;
    QCoreApplication::exec();
}
