#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>
#define PATH "./"

int tworzenie_semafora(key_t klucz);		//funkcja tworzaca semafor z wykorzystaniem funkcji semget()

key_t uzyskiwanie_dostepu();		//funkcja tworzaca klucz, ktory nastepnie jest wykorzystywany w tworzeniu semafora

void inicjowanie_semaforow(int semId);		//ustalanie wstepnej wartosci dla semaforow

void podnies_semafor (int semId);		//podnoszenie semafora za pomoca struktury sembuf

void opusc_semafor(int semId);		//opuszczanie semafora

void usuwanie_semaforow(int semId);		//usuwanie semafor za pomoca semctl()

int odczytywanie_wartosci(int semId);		//funkcja odczytujaca wartosc za pomoca funkcji semctl()

