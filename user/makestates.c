#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(void)
{
  // ZOMBIE
  int pid = fork();
  if(pid == 0){
    exit(0);
  }

  // RUNNABLE/RUNNING
  for(int i = 0; i < 4; i++){
    pid = fork();
    if(pid == 0){
      while(1){}
    }
  }

  // SLEEPING — use sleep syscall directly
  pid = fork();
  if(pid == 0){
    sleep(1000);
    exit(0);
  }

  sleep(1000);
  exit(0);
}
