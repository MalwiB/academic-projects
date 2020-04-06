#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char *argV[]) {
  
  /* zabezpieczenie przed wprowadzaniem złej ilości argumentów */
  if(argc != 3) {
    printf("Niewłaściwa ilość argumentów!\n");
    exit(1);
  }
  
  
  int sygnal, polecenie;
  sygnal = atoi(argV[1]); /* konwertowanie argumentów do liczb całkowitych */
  polecenie = atoi(argV[2]);
  printf("Sygnał: %d, polecenie: %d\n", sygnal, polecenie);
  
  
  
  pid_t pid_macierzystego;
  pid_macierzystego = getpid();
  printf("PID procesu macierzystego: %d\n", pid_macierzystego);
  
  
  pid_t pid=fork();  
  
  switch(pid) {
    case -1:
      perror("Błąd!\n");
      exit(1);
      
    case 0:
      printf("PID procesu potomnego: %d\n", getpid());
      execl("./1.x","1", sygnal, NULL); /* otwieranie programu w procesie potomnym */
      break;
	
	
    default:
      sleep(2); /* proces macierzysty czeka */
      kill(pid, sygnal); /* FUNKCJA KILL- pierwszy argument- PID procesu potomnego, drugi- numer sygnału */
      printf("Sygnał %d został przesłany do procesu potomnego o numerze PID %d\n", sygnal, pid);
      break;
      
  }
  
  
  return 0;
}
