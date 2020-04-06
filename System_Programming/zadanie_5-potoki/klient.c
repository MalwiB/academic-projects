#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define WYJSCIE 1

int main(int argc, char *argV[]) {
  
  if(argc != 3) {	//obsługa błędów
    printf("Niewłaściwa ilość argumentów w programie 'klient'\n");
    exit(1);
  }
  
  
  int filedes;
  char bufor[10];
  
  char *nazwa_potoku;
  nazwa_potoku = argV[1];
  
  char  *nazwa_pliku2;
  nazwa_pliku2 = argV[2];
  
  
  
  int plik2;
  plik2 = open(nazwa_pliku2, O_WRONLY | O_CREAT, 0644);	//plik otwarty do pisania
  if (plik2 == -1) {
    perror("Plik do którego zapisujemy nie został otwarty");
    close(nazwa_potoku);	//zamykanie i usuwanie potoku w razie gdy plik nie zostanie otwarty, a program bedzie przerwany
    remove(nazwa_potoku);
    exit(2);
  }
  
  filedes = open(nazwa_potoku, O_RDONLY);		//potok otwarty do czytania
  if(filedes == -1){
    perror("Błąd funkcji open");
    exit(3);
  }
  
  
  int bity =0;
  
  int liczba;
  srand(time(0)); 
  
  bity = read(filedes, bufor, sizeof(bufor));	//czytanie z filedes - zapisywanie do bufora -ile
  if(bity == -1) {
    perror("Błąd funkcji read");
    exit(4);
  }
  
  while(bity > 0) {
    liczba = (rand()%5);			//losowanie liczby do uśpienia
    sleep(liczba);
    if(write(plik2, bufor, bity) == -1) {		//do czego(do pliku) - z czego(z bufora) - ile
      perror("Błąd funkcji write");
      exit(9);
    }
    if (write(WYJSCIE, bufor, bity) == -1) {		//do czego(na wyjście) - z czego(z bufora) - ile
      perror("Błąd funkcji write");
      exit(9);
    }
    printf("~~przesłano z potoku fifo do pliku\n");
    bity = read(filedes, bufor, sizeof(bufor));		//nowa wartość zmiennej bity
    if(bity == -1) {
      perror("Błąd funkcji read");
      exit(4);
    }
    
  }
  
  if(close(filedes) == -1) {
    perror("Błąd funkcji close");
    exit(8);
  }
  
  printf("\n\nZapisano z potoku fifo do pliku %s\n\n", nazwa_pliku2);
  
  
  
  return 0;
}
