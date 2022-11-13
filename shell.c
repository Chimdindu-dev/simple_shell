#include "main.h"


int main(){

    char *command;
    int byteread;
    size_t size = 100;
    char *argVec[2];
    /*char *envVec[] = {NULL};*/
    /*char *token[10];*/
    /*char delimiters[] = " ;";*/
    /*int i = 0;*/

    command = (char*)malloc(size);
    prompt:
    printf("Chimdi@ALXCLI-$ ");

    byteread = getline(&command,&size,stdin); /* if u want to pass dont use getline just use getdeli and pass newline*/
    command[strcspn(command, "\r\n")] = 0; /*get rid of last null in string*/
    argVec[0] = command;
    argVec[1] = NULL;
    /* i have my own strtok replace later */
    /* splits up the string */
    /**token[i] = strtok(command, delimiters);
     *for (i=1;i<9;i++){
     *  printf("%s\n", token[i]);
     *   token[i] = strtok(NULL, delimiters);
     *}
     */

    if(byteread != -1){
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
                execvp(command,argVec);
                /*execve(command,argVec,envVec);*/
                if(!strcmp(command,"\0")){
                    goto prompt;
                }else if(!strcmp(command,"exit")){

                        exit(0); /*it works but i created i new process try to only for if command found    */       
                }
                else{

                    printf("%s: command not found\n",command);
                }
            }
    }else{
        goto prompt;
    }

    goto prompt;

    return 0;

    
}