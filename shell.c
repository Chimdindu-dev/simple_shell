#include <stdio.h>

/**
 * wait for user to write a command and 
 * print the command in the next line
 * so when user presses enter thats the eof
 */

int main(){
    
    char command[100];
    printf("#cisfun$ ");
    scanf("%[^\n]",command);
    printf("%s\n",command);
    
}