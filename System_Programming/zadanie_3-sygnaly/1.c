#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>


#define domyslne SIG_DFL
#define ignorowanie SIG_IGN




void przejmowanie(int sygnal) {
  printf("Sygnał o numerze %d został przejęty", sygnal);
}



int main(int argc, char *argV[]) {
  /* pierwszy argument- numer sygnału, drugi argument- polecenie */
  
  if(argc != 3) {
    printf("Niewłaściwa ilość argumentów\n");
    return 1;
  }
  
  
  int sygnal, polecenie;
  sygnal = atoi(argV[1]); /* konwertowanie argumentu do liczb całkowitych */
  polecenie = atoi(argV[2]);
  printf("sygnał- %d, polecenie- %d\n", sygnal, polecenie);
  
  
  
  pid_t pid;
  pid = getpid();
  printf("%d- PID procesu\n", pid);

  
  /* 1- domyślna obsługa programu, 2- ignorowanie sygnału, 3- przechwycenie sygnału */
  switch(polecenie) {
    /* domyślna obsługa sygnału */
    case 1:
      printf("Sygnał obsługiwany domyślnie\n");
      /* obsługa błędów */
      if (signal(sygnal, domyslne) == SIG_ERR) {
	perror("Błąd funkcji signal\n");
	exit(1);
      }
      break;
    case 2:
      printf("Ignorowanie sygnału\n");
      /* obsługa błędów */
      if (signal(sygnal, ignorowanie) == SIG_ERR) {
	perror("Błąd funkcji signal\n");
	exit(1);
      }
      break;

    case 3:
      printf("Przejmowanie sygnału\n");
      void (*przechwyc)(int);
      przechwyc = przejmowanie;
      /* obsługa błędów */
      if (signal(sygnal, przechwyc) == SIG_ERR) {
	perror("Błąd funkcji signal\n");
	exit(1);
      }
      break;
  }
  pause();	/* oczekuje na nadejście sygnału */
  
  
  
  return 0;
}
