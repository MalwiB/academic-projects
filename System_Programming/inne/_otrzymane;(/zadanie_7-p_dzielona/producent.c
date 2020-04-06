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
  
  
  
  
  //wskaznik do struktury bufor typu bufor_cykliczny
  struct bufor_cykliczny* bufor;
  void* adres;
  adres = dolaczenie_segmentu(Id_pamieci);
  bufor = (struct bufor_cykliczny*) adres;	//umieszczamy bufor w pamieci dzielonej
  
  
  
  int magazyn = open("magazyn.txt", O_RDONLY, 0666); //otwarcie pliku do czytania
  if(magazyn == -1)
  {
    perror("blad open- producent");
    odlaczanie_segmentu(adres);		//odlaczenie segmentu pamieci
    usuwanie_semaforow(Id_sem1);	//usuniecie semaforow
    usuwanie_semaforow(Id_sem2);
    usuwanie_segmentu(Id_pamieci);	//usuniecie segmentu pamieci dzielonej
    exit(1);
  }
  
  
  
  
  int bity;
  bity = -1; 
  int i = 0;
  
  
  bity = read(magazyn, bufor->cykliczny[i % ROZMIAR_BUFORA], sizeof(bufor->cykliczny[i % ROZMIAR_BUFORA]));
  if(bity == -1)
  {
    perror("blad przeczytanych bitow- producent");
    odlaczanie_segmentu(adres);		//odlaczenie segmentu pamieci
    usuwanie_semaforow(Id_sem1);	//usuniecie semafora1
    usuwanie_semaforow(Id_sem2);
    usuwanie_segmentu(Id_pamieci);	//usuniecie segmentu pamieci dzielonej
    exit(1);
  }
  
  
  
  buf.sem_op = 1; // ustawianie semafora na 1
  semop(Id_sem1, &buf, 1);
  
  
  srand(time(NULL));
  while(bity > 0)
  {
    buf.sem_op = -1; 
    semop(Id_sem2, &buf, 1);
    if(bity < ROZMIAR) //jesli nie zapiszemy calego bufora cyklicznego
    {
      int k = 0;
      for(k = bity; k < ROZMIAR; k ++)
      {
	bufor->cykliczny[i % ROZMIAR_BUFORA][k] = '\0';
      }
    }
    sleep(rand() % 4);
    i++;
    bity = read(magazyn, bufor->cykliczny[i % ROZMIAR_BUFORA], sizeof(bufor->cykliczny[i % ROZMIAR_BUFORA]));
    
    printf("Zapisano do bufora cyklicznego %s\n", bufor->cykliczny[i % ROZMIAR_BUFORA]);
    
    buf.sem_op = 1;
    semop(Id_sem1, &buf, 1);
  }
  
  
  sleep(10);
  
  
  
  
  odlaczanie_segmentu(adres);		//odlaczenie segmentu pamieci
  
  usuwanie_semaforow(Id_sem1);	//usuniecie semaforow
  usuwanie_semaforow(Id_sem2);
  usuwanie_segmentu(Id_pamieci);	//usuniecie segmentu pamieci dzielonej
  
  return 0;
}
