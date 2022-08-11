#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "clock_impl.h"

using namespace std;

int main()
{
    Clock *clock = new Clock();
    clock->printTime();
    while(true)
    {
        clock->incrementSeconds();
        sleep(1);
        clock->printTime();
    }
    return 0;
}
