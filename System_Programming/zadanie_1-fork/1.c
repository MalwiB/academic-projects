#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  /*Wypisywanie UID, PID, PPID, PGID procesu */
  printf("UID %d, GID %d, PID %d, PPID %d, PGID %d\n", getuid(), getgid(), getpid(), getppid(), getpgid(0));
  return 0;
  
}
