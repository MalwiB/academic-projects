#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define WYJSCIE 1


int main(int argc, char* argV[]) {
  
  if(argc != 3) {	//obsługa błędów
    printf("Niewłaściwa ilość argumentów w programie 'producent'\n");
    exit(1);
  }
  
  int filedes;
  char bufor[10];
  
  
  char *nazwa_potoku;
  nazwa_potoku = argV[1];
  
  char  *nazwa_pliku;
  nazwa_pliku = argV[2];
  
  
  int plik;
  plik = open(nazwa_pliku, O_RDONLY, 0644);	//plik otwarty do czytania
  if (plik == -1) {
    perror("Plik do którego zapisujemy nie został otwarty");
    close(nazwa_potoku);	//zamykanie i usuwanie potoku w razie gdy plik nie zostanie otwarty, a program bd przerwany
    remove(nazwa_potoku);
    exit(1);
  }
  
  
  filedes = open(nazwa_potoku, O_WRONLY);	//potok otwarty do pisania
  if(filedes == -1){
    perror("Błąd funkcji open");
    exit(3);
  }
  
  int bity = 0;
  
  int liczba;
  srand(time(0));
  
  bity = read(plik, bufor, sizeof(bufor));	//czytanie z pliku - zapisywanie do bufora - rozmiar bufora
  if(bity == -1) {
    perror("Błąd funkcji read");
    exit(4);
  }
  
  while(bity>0) {
    liczba = (rand()%5);
    sleep(liczba);
    if(write(filedes, bufor, bity) == -1) {		//do czego(do potoku) - z czego(z pliku) - ile
      perror("Błąd funkcji write");
      exit(9);
    }
    if(write(WYJSCIE, bufor, bity) == -1) {			//do wyjścia(1) - z bufora - ile
    perror("Błąd funkcji write");
    exit(9);
  }
    printf("~~przesłano z pliku do potoku fifo\n");
    bity = read(plik, bufor, sizeof(bufor));	//odczytanie nowej wartości bitów
    if(bity == -1) {
      perror("Błąd funkcji read");
      exit(4);
    }
  }
  
  
  if(close(filedes) == -1) { 		//zamykanie potoku
    perror("Błąd funkcji close");
    exit(8);
  }
  
  printf("\nZapisano z pliku %s do potoku fifo\n\n", nazwa_pliku);
 
  
 return 0;
}