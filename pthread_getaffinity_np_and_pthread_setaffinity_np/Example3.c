/*
 *
 * This file contains the code which demonstrates the usage of pthread_create(), pthread_self(), pthread_join(), 
 * pthread_getaffinity_np(), pthread_setaffinity_np(), CPU_ZERO(),CPU_SET(), CPU_SETSIZE, CPU_ISSET() functions.
 * The main motive of this program to understand concepts and implementation of pthread_getaffinity_np() and 
 * pthread_setaffinity_np().
 * 
 * @author
 * Manoj Kumar
 */
#define _GNU_SOURCE      /* for cpu_set_t, CPU_ZERO(),CPU_SET(), CPU_ISSET() and CPU_SETSIZE */
#include <stdio.h>       /* for printf() */
#include <pthread.h>     /* for pthread_create(),pthread_self()  and pthread_join() */
#include <stdlib.h>      /* for sizeof() */
#include <sched.h>       /* for pthread_getaffinity_np() and pthread_setaffinity_np() */
#include <unistd.h>      /* for sleep() */

/* pthreadMessage() function */

void *pthreadMessage( void *ptr )
 {
    sleep(50);                 /* for sleep of 50 ms */
    char *msg;               /* for message */
    msg = (char *) ptr;      /* for assigns message passed by thread in main to msg */
    printf("\n%s \n", msg);    /* prints message passed by thread in main function */
    cpu_set_t      l_cpuSet;   /* for pthread_getaffinity_np() */
    int        status;     /* for pthread_getaffinity_np() */

    /* Cleares set, so it contains no CPUs */
    CPU_ZERO( &l_cpuSet );

    /* The pthread_getaffinity_np() function returns the CPU affinity mask of the thread, thread in the buffer pointed to by cpuset  */
    status = pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t),&l_cpuSet);

    /* printing return value of pthread_getaffinity_np(), it will return 0 when successful
       otherwise , negative values.
    */

    printf("get affinity %d\n",status); /* prints pthread_getaffinity_np() return value */

    /* using pthread_self() get current thread id */
    printf ("Thread id %lu\n", pthread_self());    /* prints current thread id */

    /* The pthread_getaffinity_np() function returns the CPU affinity mask of the thread, thread in the buffer pointed to by cpuset  */
    if ( pthread_getaffinity_np(pthread_self(),sizeof( cpu_set_t ), &l_cpuSet ) == 0 )
        for (int i = 0; i < CPU_SETSIZE; i++)
            if (CPU_ISSET(i, &l_cpuSet))         /* Test to see if CPU cpu is a member of set. */
                printf("XXXCPU: CPU %d\n", i);   /* prints CPU details */
    for (long long int i=0; i< 100000000000; ++i);
 }

/* main() function is here */

int main()
 {
    /* declaring threads */

    pthread_t thread1; /* for thread 1 */
    pthread_t thread2; /* for thread 2 */
    pthread_t thread3; /* for thread 3 */
    pthread_t thread4; /* for thread 4 */

    /* declaring cpu */

    cpu_set_t cpu1;  /* for cpu 1 */
    cpu_set_t cpu2;  /* for cpu 2 */ 
    cpu_set_t cpu3;  /* for cpu 3 */
    cpu_set_t cpu4;  /* for cpu 4 */
 
    /* messages for thread */

    const char *thread1Msg = "Thread 1";  /* message for thread 1 */
    const char *thread2Msg = "Thread 2";  /* message for thread 2 */
    const char *thread3Msg = "Thread 3";  /* message for thread 3 */
    const char *thread4Msg = "Thread 4";  /* message for thread 4 */
 
    int thread1Create;  /* for thread 1 */
    int thread2Create;  /* for thread 2 */ 
    int thread3Create;  /* for thread 3 */
    int thread4Create;  /* for thread 4 */
    int  i;             /* for loop     */
    int  temp;          /* for pthread_setaffinity_np() */
   
    /* creating thread 1 */
    thread1Create = pthread_create(&thread1, NULL, &pthreadMessage, (void*)thread1Msg);
    sleep(1);

    /* creating thread 2 */
    thread2Create = pthread_create(&thread2, NULL, &pthreadMessage, (void*)thread2Msg);
    sleep(1);

    /* creating thread 3 */
    thread3Create = pthread_create(&thread3, NULL, &pthreadMessage, (void*)thread3Msg);
    sleep(1);

    /* creating thread 4 */
    thread4Create = pthread_create(&thread4, NULL, &pthreadMessage, (void*)thread4Msg);

    /*  CPU 1  */
   
    CPU_ZERO(&cpu1);    /* Clears set, so that it contains no CPUs  */
    CPU_SET(0, &cpu1);  /*  Add CPU cpu1 to set  */

    /* sets the CPU affinity mask of the thread, thread to the CPU set pointed to by cpuset */
    temp = pthread_setaffinity_np(thread1, sizeof(cpu_set_t), &cpu1);

    printf("setaffinity=%d\n", temp); /* prints pthread_setaffinity_np() return value */

    printf("Set returned by pthread_getaffinity_np() contained:\n");

    for (i = 0; i < CPU_SETSIZE; i++)
        if (CPU_ISSET(i,&cpu1))	    /* Test to see if CPU cpu is a member of set. */
            printf("CPU1: CPU %d\n", i);

    /* CPU 2  */

    CPU_ZERO(&cpu2);     /*  Clears set, so that it contains no CPUs */
    CPU_SET(1,&cpu2);    /*  Add CPU cpu2 to set */

    /* sets the CPU affinity mask of the thread, thread to the CPU set pointed to by cpuset */
    temp = pthread_setaffinity_np(thread2, sizeof(cpu_set_t), &cpu2);

    for (i = 0; i < CPU_SETSIZE; i++)
        if (CPU_ISSET(i, &cpu2))             /* Test to see if CPU cpu is a member of set. */
            printf("CPU2: CPU %d\n", i);

    /* CPU 3  */ 

    CPU_ZERO(&cpu3);     /*  Clears set, so that it contains no CPUs */
    CPU_SET(2, &cpu3);   /*  Add CPU cpu3 to set */
 
    /* sets the CPU affinity mask of the thread, thread to the CPU set pointed to by cpuset */
    temp = pthread_setaffinity_np(thread3, sizeof(cpu_set_t), &cpu3);

    for (i = 0; i < CPU_SETSIZE; i++)
        if (CPU_ISSET(i, &cpu3))              /* Test to see if CPU cpu is a member of set. */
            printf("CPU3: CPU %d\n", i);

    /* CPU 4 */

    CPU_ZERO(&cpu4);   /*  Clears set, so that it contains no CPUs */
    CPU_SET(3,&cpu4);  /*  Add CPU cpu4 to set */

    /* sets the CPU affinity mask of the thread, thread to the CPU set pointed to by cpuset */
    temp = pthread_setaffinity_np(thread4, sizeof(cpu_set_t), &cpu4);

    for (i = 0; i < CPU_SETSIZE; i++) 
        if (CPU_ISSET(i, &cpu4))              /* Test to see if CPU cpu is a member of set. */
            printf("CPU4: CPU %d\n", i);

    /*  Wait for the threads to end.*/
    pthread_join(thread1, NULL);

    /*  Wait for the threads to end.*/
    pthread_join(thread2, NULL);

    /*  Wait for the threads to end.*/
    pthread_join(thread3, NULL);

    /*  Wait for the threads to end. */
    pthread_join(thread4, NULL);

    return 0;
 }

/************************************************* EOF ******************************************************/
