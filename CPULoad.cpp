/*
This application simulates a CPU load of 50% to each core of a 4 core processor.

Miguel Pulido
Systems Architect
*/

#include <iostream>
#include <windows.h>    //Include Windows.h file to run within Windows Environment
#include <process.h>    //Declarations and macros used with threads and processes
#include <time.h>       //Used to get and manipulate date and time information
#include <stdio.h>      // Standard Input / Output header file




void CPU_Load(void *)   //Declares a function CPU_Load [Thread]
{
    while(1)            //forever while loop until 0
    {


        //Use clock_t to return value by clock. Computes a wake up time 50 ticks in the future and spins until that time is reached.
        clock_t wakeup = clock() + 50;      // clock_t (function for clock tick counts),wakeup (variable) = clock() calculates processing time of a program + 50ms
        while(clock() < wakeup) {}
        Sleep(50);  // clock and sleep use the same ticks

/*
Note that clock and Sleep are not terribly accurate, and Sleep is not terribly reliable either.
On the average, the thread function should kind of work as intended, though (give or take a few percent of variation).
*/

    }
}


int main(int, char**)
{
    //int express;
    printf("Start of multi-threaded workload \n");
    int coreThread;
    for(int i=0; i < 4; i++) _beginthread( CPU_Load, 0, &coreThread ); 
    // for each core (i.e. 4 cores), create a new "CPU_Load" function thread
    // _beginthread() takes the CPU_Load method at address float &coreThead count to {4 (core)count}
    
    (void) getchar();  // getchar() stalls the program to allows you to end the program by pressing enter
    return 0;
}
