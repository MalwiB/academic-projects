#include "biblioteka_kolejki.h"


int main() {
  
  char c;
  char znak = 'A';	//do funkcji ftok w tworzenie_kolejki
  const char* sciezka = "/";
  key_t klucz = ftok(sciezka, znak);
  Id = tworzenie_kolejki(klucz);	//uzyskujemy dostep/tworzymy kolejke
  if (Id == -1) {
    perror("klient- blad funkcji tworzenie_kolejki");
    exit(1);
  }
  printf("Mamy kolejke o Id %d\n", Id);
  
  
  while(1) {
    
    msg komunikat2;	//tworzymy komunikat2 typu msg potrzebny do odebrania wiad. z kolejki
    komunikat2.mtype = TYP;
    
    rozmiar = (sizeof(komunikat2) - sizeof(long int));
    komunikat_z_kolejki(Id, &komunikat2, rozmiar, TYP);	//odbieramy komunikat z kolejki
    printf("%s zostalo odebrane z kolejki\n", komunikat2.mtext);
    
    msg komunikat3;	//komunikat3 typu msg potrzebny do wyslania przetworzonej wiad. do kolejki
    komunikat3.mtype = komunikat2.mpid;
    
    int i;
    for (i=0; i < 100; i++) {	//zamiana znaków na wielkie
      c = komunikat2.mtext[i];
      if (islower(c)) {
	c=toupper(c);
      }
      komunikat3.mtext[i] = c;	//wstawiamy do tablicy znakow wielkie litery
    }
    
    rozmiar = (sizeof(komunikat3) - sizeof(long int));
    komunikat_do_kolejki(Id, rozmiar, &komunikat3);	//przesylamy komunikat do kolejki
    printf("%s zostalo wyslane do kolejki\n", komunikat3.mtext);
  }
  
  usuwanie_kolejki(Id);	//usuwamy kolejke, mozna to zrobic takze komenda -ipcrm w terminalu
  
  return 0;
}