#include "apue.h"

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    printf("## ");
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }

        pid = fork();
        printf("pid1 : %d \n", pid);
        if (pid < 0 )
        {
            err_sys("fork error");
        }
        
        printf("pid2 : %d \n", pid);
        if (pid == 0)
        {
            execlp(buf, buf, (char *) 0 );
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        printf("pid3 : %d \n", pid);
        if((pid = waitpid(pid, &status, 0)) < 0 )
            err_sys("waitpid error");

        printf("pid4 : %d \n", pid);
        printf("## ");
    }
}
