#include "biblioteka.h"


struct bufor_cykliczny
{
  char cykliczny[ROZMIAR_BUFORA][ROZMIAR];
};







int main() {
  
  
  
  struct sembuf buf = {0, 0, 0};
  
  int Id_sem1 = tworzenie_semafora(5);
  inicjowanie_semaforow_na_1(Id_sem1);
  
  int Id_sem2 = tworzenie_semafora(6);
  inicjowanie_semaforow_na_0(Id_sem2);
  
  printf("Utworzono semafory o Id %d i %d\n", Id_sem1, Id_sem2);
  
  
  
  char* sciezka = "./";
  char znak = 'B';
  key_t klucz = uzyskiwanie_dostepu(sciezka, znak);
  int Id_pamieci = tworzenie_segmentu(sciezka, znak, sizeof(struct bufor_cykliczny));	//segment pamieci stworzony
  printf("Utworzono segment pamieci dzielonej o Id = %d\n", Id_pamieci);
  
  
  
  struct bufor_cykliczny *bufor;
  void* adres;
  adres = dolaczenie_segmentu(Id_pamieci);
  bufor = (struct bufor_cykliczny*) adres;
  
  
  
  int produkt = open("produkt.txt", O_WRONLY | O_CREAT, 0666); // otwarcie pliku do czytania
  if(produkt == -1)
  {
    perror("blad open- klient");
    odlaczanie_segmentu(adres);		//odlaczenie segmentu pamieci
    usuwanie_semaforow(Id_sem1);	//usuniecie semafora1
    usuwanie_semaforow(Id_sem2);
    usuwanie_segmentu(Id_pamieci);	//usuniecie segmentu pamieci dzielonej
    exit(1);
  }
  
  
  
  
  int i = 0;
  
  int bity;
  bity = 0;
  
  int k = 0;
  srand(time(NULL));
  while(bity == ROZMIAR || bity == 0) {
    buf.sem_op = -1;
    semop(Id_sem1, &buf, 1);
    bity = 0;
    sleep(rand() % 4);
    for(k = 0; k < ROZMIAR; k++) {	 // sprawdzanie czy wszystko jest zapisane do bufora
      if(bufor->cykliczny[i % ROZMIAR_BUFORA][k] != '\0') {
	bity++;
	
      }
    }
    
    
    write(produkt, bufor->cykliczny[i % ROZMIAR_BUFORA], bity); // pisanie do pliku
    buf.sem_op = 1; // otwarcie semafora
    semop(Id_sem2, &buf, 1);
    i++;
  }
  
  
  odlaczanie_segmentu(adres);		//odlaczenie segmentu pamieci
  usuwanie_semaforow(Id_sem1);		//usuniecie semafora1
  usuwanie_semaforow(Id_sem2);
  usuwanie_segmentu(Id_pamieci);	//usuniecie segmentu pamieci dzielonej
  return 0;
}
