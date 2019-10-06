/*
 * pthread_create() : create a new thread 
 * pthread_exit() : terminate calling thread
 *
 * This program demonstrate concept of thread that writes to stdout 
 * while the initial thread is blocked in a read from stdin.
 *
 * @author
 * Manoj Kumar
 *
 * Note : compile with -lpthread
 */

#include<stdio.h>    /** for printf() **/
#include<pthread.h>  /** for pthread_create() and pthread_exit() **/

void *writtingThread(void *str);  /** Thread Handler **/

/** main() **/

int main (int argc, char *argv[])
  {
    pthread_t threadId;  /** ID returned by pthread_create() **/
    char  *reading;      /** for user input **/
    char  readbuf[100];  /** for user input **/

    /** create a new thread **/

    pthread_create(&threadId, NULL, writtingThread, NULL);

    /** reading a line at a time as user input **/

    reading = fgets (readbuf, 100, stdin);

    if (reading != NULL)  
       printf ("You entered :  %s\n", readbuf);

    /** terminate calling thread **/
    pthread_exit (NULL);

    return 0;
  }

void *writtingThread(void *str)
 {
   sleep(5);
   printf("This Writting Thread \n");
 }
