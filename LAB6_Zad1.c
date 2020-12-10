#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#define NAZWA_PLIKU "doObserwacji"

#define SIZE 256
int main(int argc, char *argv[])
{
   int fd =0;
   char nazwaPliku[50];
   struct stat FileStatistic;    //struktura do odczytania informacji o pliku
   char *pamiec;
   int in_fd;
   int size = 0;

   while (1)
   {
       fd = open(NAZWA_PLIKU,O_RDWR);               //tu bedzie przekazywany tekst
       printf("Nazwa pliku: ");
       scanf("%s",nazwaPliku);
       
        while(in_fd < 0)
       {
           printf("Niepoprawny plik, Podaj jeszcze raz nazwe\n");
           scanf("%s",nazwaPliku);
       }
       stat(nazwaPliku, &FileStatistic);   //pobranie informacji o pliku
       size = FileStatistic.st_size;        //wpisanie rozmiaru
       ftruncate(fd, size);                 //obcinamy ten do odbierania do rozmiaru pliku z ktorego bedzie transfer
       pamiec = mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);//NULL najlepsza możliwa lokalizacja do zmapowania
       in_fd = open(nazwaPliku,O_RDWR);         //otwieramy plik w ktorym bedziemy wpisywac
       read(in_fd, pamiec,size);
      
        close(fd);
        close(in_fd);

   }
   //Rozmiar pliku jest zmieniany po kazdym wywolaniu
}