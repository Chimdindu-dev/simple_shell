#include "main.h"


int main(){

    char *command;
    int byteread;
    size_t size = 100;
    char* argv[100]; 
    char *argVec[2];
    char *token;
    char delimiters[] = " ;";
    int i = 0;
    command = (char*)malloc(size);
    prompt:
    printf("Chimdi@ALXCLI-$ ");

    byteread = getline(&command,&size,stdin); /* if u want to pass dont use getline just use getdeli and pass newline*/
    command[strcspn(command, "\r\n")] = 0; /*get rid of last null in string*/
    /* i have my own strtok replace later */
    /* splits up the string */
    argVec[0] = command;
    argVec[1] = NULL;

    if (!strcmp(command,"exit")){
        exit(0);
        }
    
    token = strtok(command, delimiters);
    while(token!=NULL){
        argv[i]=token;
        printf("%s\n", argv[i]);
        token = strtok(NULL, delimiters);
        i++;
    }
    argv[i]=NULL;



    if(byteread != -1){
        /*if(access(argv[0],F_OK)==0 ){*/
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
                
                execvp(argv[0],argVec);
                printf("hi");
            }
             
            }
            
    else{
        goto prompt;
    }

    goto prompt;

    return 0;

    
}