/*
* @file
* The main motive of this program to understand concepts and implementation of 
* pthread_getaffinity_np() and pthread_setaffinity_np().
* 
* @author
* Manoj Kumar
*/

#define _GNU_SOURCE      /* for CPU_ZERO(), CPU_SET(), CPU_ISSET() and CPU_SETSIZE */
#include <stdio.h>       /* for printf() */
#include <stdlib.h>      /* for sizeof() */
#include <pthread.h>     /* for pthread_self(), pthread_getaffinity_np() and pthread_setaffinity_np() */
#include <errno.h>       /* for exit() */

#define DieWithError(en, msg)   \
           do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
 {
     int  status;   /* for thread */
     int       j;   /* for loop   */
     cpu_set_t cpuset; /* for cpu    */
     pthread_t thread; /* declare a thread variable */

     thread = pthread_self();  /* pthread_self() returns current thread id */

     /* Set affinity mask to include CPUs 0 to 7 */

     CPU_ZERO(&cpuset);   /* Clears set, so it contains no CPUs */
     for (j = 0; j < 8; j++)
         CPU_SET(j, &cpuset); /* Add CPU, cpuset to set */

    /* sets the CPU affinity mask of the thread, thread to the CPU set pointed to by cpuset */
     status = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
     if (status != 0)
         DieWithError(status, "pthread_setaffinity_np");

     /* Check the actual affinity mask assigned to the thread */
     status = pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
     if (status != 0)
         DieWithError(status, "pthread_getaffinity_np");

     printf("Set returned by pthread_getaffinity_np() contained:\n");
       for (j = 0; j < CPU_SETSIZE; j++)
            if (CPU_ISSET(j, &cpuset))   /*  Test to see if CPU cpu is a member of set. */
                 printf("    CPU %d\n", j);

     exit(EXIT_SUCCESS);
 }


/*************************************** EOF ************************************************/
