#include <stdio.h>
#include <string.h>

/**
 * wait for user to write a command and 
 * print the command in the next line
 * so when user presses enter thats the eof
 */

int main(){

    char command[100];
    
    /*int val = strcmp(command,"exit"); this wont work*/

/*this works perfect dont know if best option*/
    prompt:
    printf("#cisfun$ ");
    while(scanf("%s",command)==1){
        scanf("%[^\n]",command);
        printf("%s\n",command);
        goto prompt;
    }
    return 0;

/*potentiat figure out looping fgets*/
    /**prompt
     * printf("#cisfun$ ");
     * while(!strcmp(command,"exit")){
     *     fgets(command,100,stdin);
     *    printf("%s\n",command);
     *     goto prompt;
     * }
     * return 0;
     */
    
}