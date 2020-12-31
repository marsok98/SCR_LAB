
//Watki wykonuja sie w losowej kolejnosci. 
//Program wykonuje sie quasi rownolegle

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define T_NUM 10

void *thread_func(void *thread_id)
{
    long tid = (long)thread_id;
    printf("Hello SCR. Written by thread %ld\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[T_NUM];
    for(int i=0;i<T_NUM;i++)//tu tez moze byc long
    {
        int error = pthread_create(&thread[i], NULL, thread_func, (void*)i);
        if(error)
        {
            printf("Failed to create thread #%d\n Error code: %d\n", i, error);
            exit(1);
        }
    }
    pthread_exit(NULL);
}
/* 
falcon98@Falcon98-VivoBook:~/Dokumenty/SCR7/lab7$ ./a.out 
Hello SCR. Written by thread 0
Hello SCR. Written by thread 1
Hello SCR. Written by thread 3
Hello SCR. Written by thread 2
Hello SCR. Written by thread 4
Hello SCR. Written by thread 5
Hello SCR. Written by thread 6
Hello SCR. Written by thread 7
Hello SCR. Written by thread 8
Hello SCR. Written by thread 9
falcon98@Falcon98-VivoBook:~/Dokumenty/SCR7/lab7$ ./a.out 
Hello SCR. Written by thread 0
Hello SCR. Written by thread 2
Hello SCR. Written by thread 4
Hello SCR. Written by thread 3
Hello SCR. Written by thread 1
Hello SCR. Written by thread 5
Hello SCR. Written by thread 6
Hello SCR. Written by thread 7
Hello SCR. Written by thread 8
Hello SCR. Written by thread 9
falcon98@Falcon98-VivoBook:~/Dokumenty/SCR7/lab7$ ./a.out 
Hello SCR. Written by thread 1
Hello SCR. Written by thread 2
Hello SCR. Written by thread 3
Hello SCR. Written by thread 0
Hello SCR. Written by thread 4
Hello SCR. Written by thread 5
Hello SCR. Written by thread 6
Hello SCR. Written by thread 8
Hello SCR. Written by thread 7
Hello SCR. Written by thread 9
falcon98@Falcon98-VivoBook:~/Dokumenty/SCR7/lab7$ ./a.out 
Hello SCR. Written by thread 1
Hello SCR. Written by thread 2
Hello SCR. Written by thread 0
Hello SCR. Written by thread 3
Hello SCR. Written by thread 4
Hello SCR. Written by thread 5
Hello SCR. Written by thread 6
Hello SCR. Written by thread 7
Hello SCR. Written by thread 8
Hello SCR. Written by thread 9
falcon98@Falcon98-VivoBook:~/Dokumenty/SCR7/lab7$ 
*/