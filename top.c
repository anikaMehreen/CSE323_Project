#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define MAXPROCS 64

static char *states[] = {
  "unused  ",
  "used    ",
  "sleeping",
  "runnable",
  "running ",
  "zombie  "
};

int
main(void)
{
  struct procinfo procs[MAXPROCS];

  while(1){
    printf("\033[2J\033[H");
    printf("PID\tNAME\t\tSTATE\t\tTICKS\n");
    printf("---\t----\t\t-----\t\t-----\n");

    int n = getprocs(procs, MAXPROCS);

    for(int i = 0; i < n; i++){
      char *state = (procs[i].state >= 0 && procs[i].state < 6)
                    ? states[procs[i].state] : "???";
      printf("%d\t%s\t\t%s\t\t%d\n",
             procs[i].pid,
             procs[i].name,
             state,
             (int)procs[i].cputicks);
    }
    sleep(100);
  }
  exit(0);
}
