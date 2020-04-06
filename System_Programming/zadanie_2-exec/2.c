#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
  
  printf("macierzysty: UID %d, GID %d, PID %d, PPID %d, PGID %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(0));
  int i;

  for(i=1; i<=3; i++) {
    
    switch(fork()) {
      case -1:
	printf("fork error");
	break;
      case 0:
	execl("./1.x","1", NULL);
	perror("execl error");
	break;
      default:
	wait();
	break;
    }
  }
  
  return 0;
}
