#ifndef MTHREAD_H
#define MTHREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT

public:
    Thread();

    void someMethod();
    void stop();

protected:
    void run();

private:
    volatile bool stopped;
};

#endif // MTHREAD_H
