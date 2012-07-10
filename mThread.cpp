#include "mThread.h"
#include <iostream>

Thread::Thread()
{
    stopped = false;
}

void Thread::someMethod()
{
}

void Thread::run()
{
    while (!stopped)
    {
        std::cout << "Hello, World";
    }
    stopped = false;
    std::cout << std::endl;
}

void Thread::stop()
{
    stopped = true;
}
