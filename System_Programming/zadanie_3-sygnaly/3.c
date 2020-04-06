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
  
  
  
  pid_t pid_macierzystego, pid;
  pid_macierzystego = getpid();
  printf("PID procesu macierzystego: %d\n", pid_macierzystego);
  
   
  
  int i;
  for(i=1; i<=3; i++) {
    
    switch(fork()) {
      case -1: /* blad fork'a */
	printf("fork error");
	break;
	
      case 0: /* jestesmy w procesie potomnym */
	execl("./1.x","1", sygnal, polecenie, NULL); /* otwieranie programu w procesie potomnym */
	break;
	
      default: /* jesteśmy w procesie macierzystym, wait'em czekamy na procesy potomne */
	wait(NULL);
	break;
	
    }
    sleep(1);
  }
  
  sleep(1);
  printf("Sygnał %d został wysłany do grupy procesów o numerze %d\n", sygnal, getpgrp());
  kill(-getpgrp(), sygnal); /* funkcja kill- wysyła sygnał do grupy procesów, stąd "-getpgrp" */
  
  return 0;
}
