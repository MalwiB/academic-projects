#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#define PATH "./"

int main(int argc, char *argV[]) {
  
  if(argc != 6) {
    printf("Niewłaściwa ilość argumentów w programie 'program'\n");
    exit(1);
  }
  //argumenty: 1)nazwa potoku, 2)nazwa procesu producenta, 3)nazwa procesu klienta,
  //4)plik z którego czytamy, 5)plik do którego zapisujemy
  
  char *nazwa_potoku;
  nazwa_potoku = argV[1];
  
  char *producent;
  producent = argV[2];
  
  char *klient;
  klient = argV[3];
  
  char *nazwa_pliku;
  nazwa_pliku = argV[4];
  
  char  *nazwa_pliku2;
  nazwa_pliku2 = argV[5];
  
  
  
  char sciezka1[30];		//tworzenie łańcuchów znakowych-ścieżek do plików poprzez sprintf
  sprintf(sciezka1, "%s%s", PATH, producent);
  
  char sciezka2[30];
  sprintf(sciezka2, "%s%s", PATH, klient);
  
  
  int filedes;
  umask(0);
  
  if (mkfifo(nazwa_potoku, 0644) == -1) {	//0644-Właściciel ma prawo do zapisu i odczytu, a reszta tylko prawo odczytu
    perror("Błąd funkcji mkfifo");
    exit(2);
  }
  
  
  
  switch(fork()) { 	//proces potomny uruchamiajacy program producenta
    case -1:
      perror("Błąd funkcji fork");
      exit(3);
  
    case 0: //potomny
      execl(sciezka1, producent, nazwa_potoku, nazwa_pliku, NULL);
      
    default:
      
      switch(fork()) {	//proces potomny uruchamiajacy program klienta
	case -1:
	  perror("Błąd funkcji fork");
	  exit(3);
      
	case 0: //drugi proces potomny
	  execl(sciezka2, klient, nazwa_potoku, nazwa_pliku2, NULL);
	  
	default:
	  wait(NULL);
	  
      }
      wait(NULL);
  }  
  
  
  
  if (remove(nazwa_potoku) == -1) {		//usuwanie potoku nazwanego za pomocą funkcji remove()
    perror("Błąd funkcji remove");
    exit(4);
  }
  
  return 0;
}
