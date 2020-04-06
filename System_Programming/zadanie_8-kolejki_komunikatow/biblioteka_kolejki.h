#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <string.h>
#define TYP 8


typedef struct msgbuf {
  long mtype;
  int mpid;
  char mtext[300];
} msg;



int udane_czy_nie;
int Id;
int rozmiar;

int tworzenie_kolejki (key_t klucz);
int usuwanie_kolejki(int Id);
void komunikat_do_kolejki(int Id, int rozmiar, msg* wiadomosc);
void komunikat_z_kolejki(int Id, msg* wiadomosc, int rozmiar, int typ);