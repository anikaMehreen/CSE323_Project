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
    printf("PID\tPPID\tSZ(bytes)\tSTATE\t\tTICKS\tNAME\n");
    printf("---\t----\t---------\t-----\t\t-----\t----\n");

    int n = getprocs(procs, MAXPROCS);

    for(int i = 0; i < n; i++){
	if(procs[i].state == 0) continue;  // skip unused
      char *state = (procs[i].state >= 0 && procs[i].state < 6)
                    ? states[procs[i].state] : "???";
      printf("%d\t%d\t%d\t\t%s\t%d\t%s\n",
       procs[i].pid,
       procs[i].ppid,
       (int)procs[i].sz,
       state,
       (int)procs[i].cputicks,
       procs[i].name);
    }

    int t0 = uptime();
    while(uptime() - t0 < 100)
      ;
  }
  exit(0);
}
