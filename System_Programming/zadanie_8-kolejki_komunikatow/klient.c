#include "biblioteka_kolejki.h"


int main() {
  
  char c;
  const char znak = 'A';	//do funkcji ftok w tworzenie_kolejki
  const char* sciezka = "/";
  key_t klucz = ftok(sciezka, znak);
  
  Id = tworzenie_kolejki(klucz);	//tworzymy kolejke/uzyskujemy dostep o identyfikatorze Id
  if (Id == -1) {
    perror("klient- blad funkcji tworzenie_kolejki");
    exit(1);
  }
  printf("Mamy kolejke o Id %d\n", Id);
  
  
  msg komunikat;
  komunikat.mtype = TYP;	//przyporzadkowanie pierwszemu polu struktury wartosci TYP
  sprintf(komunikat.mtext, "We will rule over all this land and call it this land");
  
  int pid;
  pid = getpid();	//pobranie pid'u procesu do struktury przekazywanej do kolejki, zeby serwer wiedzial, gdzie odeslac przetworzony tekst
  komunikat.mpid = pid;
  
  rozmiar = (sizeof(komunikat) - sizeof(long int)); 
  komunikat_do_kolejki(Id, rozmiar, &komunikat);	//wyslanie do kolejki komunikatu
  printf("Do kolejki przeslano komunikat ");
  printf("%s\n", komunikat.mtext);
  
  komunikat.mtype = pid;	//ustawienie za typ pid'u, zeby odebrac wiadomosc z kolejki
  komunikat_z_kolejki(Id, &komunikat, rozmiar, komunikat.mtype);	//odbieranie komunikatu z kolejki
  
  printf("Z kolejki odebrano komunikat %s\n", komunikat.mtext);
  
  
  printf("Aby zakonczyc program nalezy wcisnac 'q'\n");
  if((c=getchar()) == 'q') {
    usuwanie_kolejki(Id);
    exit(2);
  }
  
  return 0;
}