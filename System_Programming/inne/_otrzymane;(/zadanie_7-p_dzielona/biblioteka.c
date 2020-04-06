#include "biblioteka.h"


//FUNKCJE SEMAFOROW

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





key_t uzyskiwanie_dostepu(char *sciezka, char znak) {
  key_t klucz = ftok(sciezka, znak); 
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



void inicjowanie_semaforow_na_1(int semId) {
  union semun inicj;
  inicj.wartosc = 1;
  if (semctl(semId, 0, SETVAL, inicj) == -1) {; //nadanie grupie semaforow o semId wartosci podanej w sterowanie.wartosc
    perror("Blad funkcji semctl w inicjowanie_semaforow");
    exit(1);
  }
}


void inicjowanie_semaforow_na_0(int semId) {
  union semun inicj;
  inicj.wartosc = 0;
  if (semctl(semId, 0, SETVAL, inicj) == -1) {	 //nadanie grupie semaforow o semId wartosci 0
      perror("Blad funkcji semctl w inicjowanie_semaforow");
      exit(1);
    }
}


/*
 * opis struktury sembuf-
 * struct sembuf {
 * ushort sem_num;	-numer semafora w zbiorze
 * short sem_op;		-rodzaj operacji na semaforze
 * ushort sem_flg;	-znacznik operacji
 * };
 * 
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












//FUNKCJE PAMIECI DZIELONEJ

int tworzenie_segmentu(char *sciezka, char znak, int rozmiar) {
  key_t klucz = ftok(sciezka, znak);
  if(klucz == -1) {
    perror("Tworzenie_segmentu- ftok error");
    exit(1);
  }
  
  int Id = shmget(klucz, rozmiar, IPC_CREAT | 0666);
  if(Id == -1) {
    perror("Tworzenie_segmentu- shmget error");
    exit(2);
  }
  
  return Id;
  
}




//		....,char cPathname[],.....
int dostep_do_segmentu(char *sciezka, char znak) {
  key_t klucz = ftok(sciezka, znak);
  if(klucz == -1) {
    perror("MemAccess (ftok error)");
    exit(1);
  }
  
  int Id = shmget(klucz, 0, IPC_CREAT | 0666);
  if(Id == -1) {
    perror("MemAccess (shmget error)");
    exit(2);
  }
  
  return Id;
}



void* dolaczenie_segmentu(int Id) {
  void* adres;
  adres = shmat(Id, NULL, 0);	//zamiast 0 moze byc np. SHM_RDONLY (0 to domysle wlasciwosci)
  
  return adres;
}



void odlaczanie_segmentu(void* adres) {
  if (shmdt(adres) == -1) {
    perror("odlaczanie_segmentu- blad shmdt");
    exit(1);
  }
}





void usuwanie_segmentu(int Id)  {
  if(shmctl(Id, IPC_RMID, (struct shmid_ds*)0) == -1) {
    perror("usuwanie_segmentu- blad shmctl");
    exit(1);
  }
  printf("segment pamieci dzielonej od Id %d zostal usuniety\n", Id);
}


