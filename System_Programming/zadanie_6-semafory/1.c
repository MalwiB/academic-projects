#include "semafory.h"


int main(int argc, char *argV[]) {
  //ARGUMENTY:
  //1- nazwa programu
  //2-liczba procesow
  //3- ilość wejść do sekcji krytycznej
  
  if(argc != 4) {
    perror("Bledna ilosc argumentow w 1.c");
    exit(1);
  }
  
  int i = 0;
  srand(time(0));
  
  char* nazwa = argV[1];
  int liczba_procesow = atoi(argV[2]);
  //int liczba_krytycznych = atoi(argV[3]);
    
  
  key_t klucz;
  klucz = uzyskiwanie_dostepu();
  
  int semId;
  semId = tworzenie_semafora(klucz);
  
  inicjowanie_semaforow(semId);
  
  printf("semId - %d, klucz - %d\n", semId, klucz);
  printf("wartosc poczatkowa semafora - %d\n", odczytywanie_wartosci(semId));
  
  
  
  char sciezka[30];
  sprintf(sciezka, "%s%s", PATH, nazwa);
  
  char id[30];
  sprintf(id, "%c", semId);

  
  for(i = 0; i <= liczba_procesow; i++) {
    
    switch(fork()) {
      case -1:
	perror("Blad funkcji fork");
	exit(1);
      case 0:		//potomny
	sleep(rand()%3);
	if (execl(sciezka, nazwa, argV[2], argV[3], NULL) == -1) {	//argV[0]- nazwa, argV[1]- liczba_procesow
	 perror("Blad funkcji execl");
	 exit(1);
	}
	break;
	
   
      default:		//macierzysty
	wait(NULL);
	break;
    }

  }
  
  
  
  
  usuwanie_semaforow(semId);  


  
  return 0;
}