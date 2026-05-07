#include "kernel/types.h"
#include "user/user.h"

int main(void) {
    int pid = mypid();
    printf("my pid is: %d\n", pid);
    exit(0);
}
