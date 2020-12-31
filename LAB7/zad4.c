
//Program konczyl dzialanie, a nie wykonal jeszcze wszystkich watkow
//Trzeba dodac na koniec funkcji main pthread_exit(NULL);
//powoduje to ze mimo main sie zakonczy reszta watkow moze dzialac nadal

//gcc bug5.c -lm -lpthread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	5

void *PrintHello(void *threadid)
{
   int i;
   double myresult=0.0;
   printf("thread=%ld: starting...\n", threadid);
   for (i=0; i<1000000; i++)
      myresult += sin(i) * tan(i);
   printf("thread=%ld result=%e. Done.\n",threadid,myresult);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for(t=0;t<NUM_THREADS;t++){
    printf("Main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc){
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
      }
    }
  printf("Main: Done.\n");
 pthread_exit(NULL);
}

/*
Main: creating thread 0
Main: creating thread 1
thread=0: starting...
Main: creating thread 2
thread=1: starting...
Main: creating thread 3
thread=2: starting...
Main: creating thread 4
thread=3: starting...
Main: Done.
thread=4: starting...
thread=4: starting...

Main: creating thread 0
Main: creating thread 1
Main: creating thread 2
thread=0: starting...
thread=1: starting...
thread=2: starting...
Main: creating thread 3
Main: creating thread 4
thread=3: starting...
Main: Done.
thread=4: starting...
thread=3 result=-3.153838e+06. Done.
thread=2 result=-3.153838e+06. Done.
thread=1 result=-3.153838e+06. Done.
thread=4 result=-3.153838e+06. Done.
thread=0 result=-3.153838e+06. Done.


 */