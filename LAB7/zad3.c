
//hello_arg1.c
//W tym programie argument pojednczy przekazujemy poprzez wskaznik na void a nastepnie go rzutujemy na odpowiedni typ

//hello_arg2.c
//W tym programie chciano przekazac wiele argumentow wiec utworzono strukture, przekazujemy void wskaznik i 
//w funkcji rzutujemy na strukture.

//bug3.c
//do funkcji byla przekazywana referencja, wiec tak naprawde wszystkie watki wspoldzielily zmienna
//8 watek nadpisal wszystko wiec wykonal sie 8 razy
//wszystkie watki wspoldzielily zmienna

//w kodzie zaznaczono miejsca ktore nalezalo poprawic

//W pierwszym programie hello jest to dobrze zrobione wiec tak naprawde wystarczylo to przepisac
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS     8

void *PrintHello(void *threadid)
{
   long taskid;
   sleep(1);
   taskid = (long)threadid;  //taskid = *(long *)threadid; tak bylo
   printf("Hello from thread %ld\n", taskid);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
pthread_t threads[NUM_THREADS];
int rc;
long t;

for(t=0;t<NUM_THREADS;t++) {
  printf("Creating thread %ld\n", t);
  rc = pthread_create(&threads[t], NULL, PrintHello, (void *) t); //&t bylo
  if (rc) {
    printf("ERROR; return code from pthread_create() is %d\n", rc);
    exit(-1);
    }
   }

pthread_exit(NULL);
}


/* 
Przed poprawa

Creating thread 0
Creating thread 1
Creating thread 2
Creating thread 3
Creating thread 4
Creating thread 5
Creating thread 6
Creating thread 7
Hello from thread 8
Hello from thread 8
Hello from thread 8
Hello from thread 8
Hello from thread 8
Hello from thread 8
Hello from thread 8
Hello from thread 8

Po:

Creating thread 0
Creating thread 1
Creating thread 2
Creating thread 3
Creating thread 4
Creating thread 5
Creating thread 6
Creating thread 7
Hello from thread 0
Hello from thread 1
Hello from thread 3
Hello from thread 2
Hello from thread 4
Hello from thread 7
Hello from thread 6
Hello from thread 5
*/