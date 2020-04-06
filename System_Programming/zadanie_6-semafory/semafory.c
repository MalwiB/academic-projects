#include "semafory.h"

//semId- numer zbioru semaforow, spr go ipcm -s
//semNum- numer semafora w zbiorze
//cmd- polecenie jakie ma byc wykonane w zbiorze semaforow




int tworzenie_semafora(key_t klucz) {
  int semId;
  semId = semget(klucz, 1, 0666 | IPC_CREAT);	//argumenty semget- klucz, 1 semafor, prawa dostepu, flaga tworzenia
  if(semId == -1) {
    perror("Blad funkcji semget");
    exit(1);
  }
  return semId;		//zwraca Id zbioru semaforow
}





key_t uzyskiwanie_dostepu() {
  key_t klucz = ftok("./1.x", 1); 
  if (klucz == -1) {
    perror("Blad funkcji ftok");
    exit(1);
  }
  return klucz;
}



union semun {		//sterowanie semaforami
  int wartosc;
  struct semId_ds *bufor;
  unsigned short *tablica;
};



void inicjowanie_semaforow(int semId) {
  union semun inicj;
  inicj.wartosc = 1;
  if (semctl(semId, 0, SETVAL, inicj) == -1) {; //nadanie grupie semaforow o semId wartosci podanej w sterowanie.wartosc
    perror("Blad funkcji semctl w inicjowanie_semaforow");
    exit(1);
  }
  }



/*
 * opis struktury sembuf-
 struct sembuf {
 ushort sem_num;	-numer semafora w zbiorze
 short sem_op;		-rodzaj operacji na semaforze
 ushort sem_flg;	-znacznik operacji
 };
 
 */


void podnies_semafor (int semId) {
  struct sembuf podnoszenie;
  podnoszenie.sem_num = 0;
  podnoszenie.sem_op = 1;
  podnoszenie.sem_flg = 0;
  semop(semId, &podnoszenie, 1);
}



void opusc_semafor(int semId) {
  struct sembuf opuszczanie;
  opuszczanie.sem_num = 0;
  opuszczanie.sem_op = 1;
  opuszczanie.sem_flg = 0;
  semop(semId, &opuszczanie, 1);
}



int odczytywanie_wartosci(int semId) {
  int wartosc = semctl(semId, 0, GETVAL, NULL);
  if (wartosc == -1) {
    perror("Blad funkcji semctl w odczytywanie_wartosci");
    exit(1);
  }
  return wartosc;
}



void usuwanie_semaforow(int semId) {
  if(semctl(semId, 0, IPC_RMID) == -1){
    perror("Blad funkcji semctl w usuwanie_semaforow");
    exit(1);
  }
  printf("Semafory o numerze semId %d zostaly usuniete\n", semId);
}