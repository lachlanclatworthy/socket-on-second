// ipc.c

#include "ipc.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

// UNIX
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#ifdef __cplusplus
namespace ipc {
extern "C" {
#endif // __cplusplus

void ex1(void) {
    pid_t pid;
    int ret;

    printf("Example 1!\n");

    switch (pid = fork()) {
    case -1:
        perror("fork");
        exit(1);
    case 0:
        printf(" CHILD: This is child process!\n");
        printf(" CHILD: My PID is %d\n", getpid());
        printf(" CHILD: My parent's PID is %d\n", getppid());
        printf(" CHILD: Enter exit status: ");
        scanf(" %d", &ret);
        exit(ret);
    default:
        printf("PARENT: This is the parent process!\n");
        printf("PARENT: My PID is %d\n", getpid());
        printf("PARENT: My child's PID is %d\n", pid);
        printf("PARENT: Waiting for child to exit...\n");
        wait(&ret);
        printf("PARENT: Child's exit status == %d\n", WEXITSTATUS(ret));
        printf("PARENT: All DONE!\n");
    }
    printf("\n");
}

void ex2(void) {
    printf("Example 2!\n");
    if (!fork()) {
        printf("This is the child!\n");
        exit(0);
    } else {
        printf("This is the parent!\n");
        wait(NULL);
    }

    printf("\n");
}

#ifdef __cplusplus
}
}
#endif // __cplusplus
