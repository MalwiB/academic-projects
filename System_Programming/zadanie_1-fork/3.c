#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
int main() {
  int i,a=0;
  
  printf("macierzysty- UID %d, GID %d, PID %d, PPID %d, PGID %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(0));
  
  sleep(1);
  
  for(i=0; i<3; i++) {
    
    switch(fork()) {
      case -1: /*blad fork'a*/
	printf("fork error");
	break;
      case 0:/*jestesmy w procesie potomnym*/
	a++;
	sleep(i*a); /*proces czeka*/
	printf("UID %d, GID %d, PID %d, PPID %d, PGID %d, a %d, i %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(0), a, i);
	break;
      default:/*proces macierzysty, nic sie tu nie dzieje*/
	break;
    }
  }
  
  sleep(9);
  return 0;

}
