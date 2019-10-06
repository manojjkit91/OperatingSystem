/**
 * pthread_create() : create a new thread
 * pthread_join()  : join with a terminated thread
 * 
 * This program implements pthread_create() and pthread_join()
 * To demonstrate the concept of threads
 * 
 * @author
 * Manoj Kumar
 * 
 * Note : compile with -lpthread.
 **/

#include<stdio.h>   /** for printf() **/
#include<stdlib.h>  /** for exit()  **/
#include<pthread.h> /** pthread_create() and pthread_join() **/

void *myThread( void *msgPtr );   /** for thread handling **/
void DieWithError(char *Err);     /** for Error Handling **/

/** main() **/

int main()
  {
     pthread_t thread1;         /** for thread1 : ID returned by pthread_create() **/  
     pthread_t thread2;         /** for thread3 : ID returned by pthread_create() **/
     char *msg1 = "Hi, I am Thread 1.";      /** for Thread 1 **/
     char *msg2 = "Hello, I am Thread 2.";   /** for thread 2 **/
     int  checkThread1; /** for thread1 : return value of pthread_create() **/
     int  checkThread2; /** for thread2 : return value of pthread_create() **/

     /** Create independent threads **/

     checkThread1 = pthread_create( &thread1, NULL, myThread, (void*) msg1); 
     if (checkThread1 != 0)  /** Thread 1 creation successful or not **/
	{
           DieWithError("Thread 1 : pthread_create() failed!!"); /** DieWithError() call **/
        }
     checkThread2 = pthread_create( &thread2, NULL, myThread, (void*) msg2);
     if (checkThread2 != 0) /** Thread 2 creation successful or not **/
	{
           DieWithError("Thread 2 : pthread_create() failed!!");   /** DieWithError() call **/
        }

     /** Wait till threads are complete before main continues. Unless we  **/
     /** wait we run the risk of executing an exit which will terminate   **/
     /** the process and all threads before the threads have completed.   **/

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d\n",checkThread1);
     printf("Thread 2 returns: %d\n",checkThread2);
     return 0;
  }

/** Thread Handling function **/

void *myThread( void *msgPtr )
 {
     char *msg;
     msg = (char *) msgPtr;
     printf("%s \n", msg);
 }

/** Error handling function definition **/

void DieWithError(char *Err)
 {
   printf("%s",Err);
   exit(0); /** cause normal process termination **/
 }

/** End of the program **/
