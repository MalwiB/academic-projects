#include "semafory.h"


int main(int argc, char *argV[]) {
  
  //1- nazwa programu
  //2-liczba procesow
  //3- ilość wejść do sekcji krytycznej
  
  if(argc != 3) {
    perror("Bledna ilosc argumentow w 2.c");
    exit(1);
  }
  
  
  
  key_t klucz;
  klucz = uzyskiwanie_dostepu();
  
  int semId;
  semId = tworzenie_semafora(klucz);
  
  inicjowanie_semaforow(semId);
  
  
  int i;   
  int liczba_krytycznych = atoi(argV[2]);
    
  
  srand(time(0));
  
  
  opusc_semafor(semId);
  
  
  for (i = 1; i <= liczba_krytycznych; i++) {
    printf("Semafor w sekcji krytycznej nr %d  ~  ", i);
    
    
    printf("PID procesu- %d, wartosc semafora- %d\n", getpid(), odczytywanie_wartosci(semId) );    
    sleep(rand()%4);
    
    
  }
  
  
  printf("Semafor wyszedl z sekcji krytycznej ~~  ");
  printf("PID procesu- %d, wartosc semafora- %d\n", getpid(), odczytywanie_wartosci(semId) );
  
  printf( "procesy czekajace na podniesienie- %d, procesy czekajace na opuszczenie- %d\n\n", semctl(semId, 0, GETNCNT), semctl(semId, 0, GETZCNT));
  
  podnies_semafor(semId);
  
  
  
  return 0;
}
