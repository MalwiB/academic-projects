#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#define PATH "./"
#define ROZMIAR_BUFORA 40
#define ROZMIAR 7



//NAGLOWKI FUNKCJI SEMAFOROW
int tworzenie_semafora(key_t klucz);		//funkcja tworzaca semafor z wykorzystaniem funkcji semget()

key_t uzyskiwanie_dostepu(char *sciezka, char znak);		//funkcja tworzaca klucz, ktory nastepnie jest wykorzystywany w tworzeniu semafora

void inicjowanie_semaforow_na_1(int semId);

void inicjowanie_semaforow_na_0(int semId);

void inicjowanie_semaforow(int semId);		//ustalanie wstepnej wartosci dla semaforow

void podnies_semafor (int semId);		//podnoszenie semafora za pomoca struktury sembuf

void opusc_semafor(int semId);		//opuszczanie semafora

void usuwanie_semaforow(int semId);		//usuwanie semafor za pomoca semctl()

int odczytywanie_wartosci(int semId);		//funkcja odczytujaca wartosc za pomoca funkcji semctl()


//NAGLOWKI FUNKCJI PAMIECI DZIELONEJ


int tworzenie_segmentu(char *sciezka, char znak, int rozmiar);

int dostep_do_segmentu(char *sciezka, char znak);

void* dolaczenie_segmentu(int Id);

void odlaczanie_segmentu(void* adres);

void usuwanie_segmentu(int id);
