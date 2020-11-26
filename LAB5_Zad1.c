#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 256
int main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t id_copy;
    char bufor;
    char *napis = "Wyswietlam plik\n";
    char buforFile[SIZE];
    if (argc != 2) 
    {
        fprintf(stderr, "Skladnia: %s <string>\n", argv[0]);
        return -1;
    }
    int status_pipe = pipe(pipefd);
    if(status_pipe == -1) 
    {
        perror("Blad tworzenia potoku");
        return -2;
    }

    id_copy = fork();

    if (id_copy == -1) 
    {
        perror("Blad tworzenia nowego procesu");
        return -3;
    }

    if (id_copy == 0) //Proces dziecka
    {
        close(pipefd[1]);          //Zamykamy niepotrzebne pisanie do potoku
        while (read(pipefd[0], &bufor, 1) > 0)
        {
            write(STDOUT_FILENO, &bufor, 1);
            write(STDOUT_FILENO, "#",1);
        }
        write(STDOUT_FILENO, "\n", 1);
        
        //dup(pipefd[0]);
        close(pipefd[0]);
    }
    else                            //Proces rodzica
    {   
        close(pipefd[0]);          //Zamykamy niepotrzebne czytanie z potoku
       // FILE *f = fopen(argv[1], "r"); // "r" for read
       //fscanf(f, "%s",buforFile);
        int in_fd = open(argv[1], O_RDONLY); //zwraca indentyfikator
        while(read(in_fd, buforFile, SIZE)>0);
        
        //fclose(f);
        //printf("%s",buforFile);
        write(pipefd[1], buforFile, strlen(buforFile)); 
        write(1, napis, strlen(napis));//1 jako standardowe wyjscie
        write(1, buforFile, strlen(buforFile));
        write(1, "\n\n", 2);
        close(pipefd[1]);         
    }
}