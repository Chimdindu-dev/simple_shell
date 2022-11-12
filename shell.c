#include "main.h"


int main(){

    char command[100];
    char *argVec[] = {"ls",NULL};
    char *envVec[] = {NULL};

    prompt:
    printf("Chimdi'sSystem-$ ");
    while(scanf("%s",command)==1){
        scanf("%[^\n]",command);
        if(!strcmp(command,"ls")){
            /*pid_t parent = getpid();*/
            pid_t pid = fork();

            if (pid == -1)
            {
                perror("cant fork");
            } 
            else if (pid > 0)
            {
            int status;
            waitpid(pid, &status, 0);
            }
            else 
            {
            execve("/usr/bin/ls",argVec,envVec);;
    /*_exit(EXIT_FAILURE);   exec never returns*/
            }
        }
        else{
        printf("%s\n",command);
        }
        goto prompt;
    }




    return 0;

    
}