

========================================================================================================
  Examples : pthread_getaffinity_np() and pthread_setaffinity_np()

  @author
         -- Manoj Kumar

========================================================================================================

There are 5 files(excluding ReadMe.txt) :

	1. Makefile
        2. Example1.c
	3. Example2.c
        4. Example3.c

******************************************* Makefile *****************************************************

1. Makefile: 

make 
      Will compile the code and keep track of dependencies, so that the code is recompiled correctly when any
      of the source code is modified.

make all 
	(will compile all the code)

make clean 
	(will remove object files)


***************************************** Example1.c  ***************************************************
2. Example1.c :

         Simple program for pthread_getaffinity_np() and pthread_setaffinity_np() functions.In this program 
         just setting cpu and printing CPU numbers.

   syntax: 
      	./Example1.out

******************************************* Example2.c **************************************************
3. Example2.c :

    ->  This program demonstrates the concepts of pthread_getaffinity_np() and pthread_setaffinity_np() 
        using 4 thread and each thread having separate functions. where first thread will execute first CPU,
        second thread will in second CPU,third thread will in third CPU and fourth thread wil in fourth CPU.

    ->  Prints CPU number, thread number , thread Id, getaffinity return value, setaffinity return value.    

  syntax : 
	./Example2.out

***************************************** Example3.c ****************************************************
3. Example3.c :

    ->  This program demonstrates the concepts of pthread_getaffinity_np() and pthread_setaffinity_np() 
        using 4 thread and one thread function. where first thread will execute first CPU,second thread 
        will in second CPU,third thread will in third CPU and fourth thread wil in fourth CPU.

    ->  Prints CPU number, thread number , thread Id, getaffinity return value, setaffinity return value.    

  syntax : 
	./Example3.out


