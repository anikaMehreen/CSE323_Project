#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    printf("Calling hello system call...\n");
    hello();
    printf("System call completed!\n");
    exit(0);
}
