#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

//wyswietlenie komunikatu i zakonczenie pracy programu
void catchSIGALRM(int signal)
{
    printf("SIGALRM\n");
    exit(-1);
}
//wyswietlenie i powrot do wykonywania programu
void catchSIGTERM(int signal)
{
    printf("SIGTERM\n");
}
//wstrzymywanie odebrania sygnału i następnie wznowienie odebrania sygnału
void catchSIGUSR1(int signal)
{
    printf("Zlapano SIGUSR1");
    for(int i=0;i<1000;i++)
    {
        printf("%d",i);
        //sleep(1);
    }
}
//całkowite ignorowanie sygnału
void catchSIGUSR2(int signal)
{
    
}

int main()
{
    signal(SIGUSR1,catchSIGUSR1); //10
    signal(SIGUSR2,catchSIGUSR2); //12
    signal(SIGALRM,catchSIGALRM);//14
    signal(SIGTERM,catchSIGTERM);//15

    while(1)
    {
        printf("Kontynuuje zadanie\n");
        sleep(1);
    }
    return 0;
}
