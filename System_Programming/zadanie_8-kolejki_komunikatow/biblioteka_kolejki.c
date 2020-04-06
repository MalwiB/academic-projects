#include "biblioteka_kolejki.h"



int tworzenie_kolejki (key_t klucz) {
  Id = msgget(klucz, IPC_CREAT | 0666);
  if(Id == -1) {
    perror("tworzenie_kolejki- msgget error");
    exit(1);
  }
  return Id;
}



int usuwanie_kolejki(int Id) {
  msgctl(Id, IPC_RMID, NULL);
  return udane_czy_nie;
}




void komunikat_do_kolejki(int Id, int rozmiar, msg* wiadomosc) {
  
  if (msgsnd(Id, wiadomosc, rozmiar, 0) == -1) {
    perror("komunikat_do_kolejki- msgnd error");
    exit(2);
  }
  
}


void komunikat_z_kolejki(int Id, msg* wiadomosc, int rozmiar, int typ) {
  
  if (msgrcv(Id, wiadomosc, rozmiar, typ, 0) == -1) {
    perror("komunikat_z_kolejki- msgrcv error");
    exit(3);
  }
  
}