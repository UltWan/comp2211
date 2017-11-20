#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  char command[50];
  char exit[6] = "exit\n";
  char info[6] = "info\n";
  char pwd[5]= "pwd\n";
  char cwd[50];
  char cd[50]= "cd /";
  char *chwd = command + 3;

  // loop does not exit until exit command is entered
  while (strcmp(command, exit) != 0){
    printf("Enter command: ");
    fgets(command, sizeof command, stdin);
    printf("You have selected command: %s", command);

    if (strcmp(command, info) == 0){
      printf("COMP2211 Simplified Shell by sc16wyrw\n\n");
    }

    // gets and prints current working directory
    if (strcmp(command, pwd) == 0){
      getcwd(cwd, sizeof(cwd));
      printf("The current working directory is: %s\n\n", cwd);
    }

    // changes current working directory
    if (strncmp(command, cd, 4) == 0){
      chdir(chwd);
      printf("5) The current working directory is: %s\n", chwd);
      getcwd(chwd, sizeof(chwd));
      printf("Switched current working directory to: %s\n\n", chwd);
      strcpy(cwd, chwd);
    }

    /*else{
      printf("No such command found\n\n");
    }*/
  }
  printf("Exiting shell\n");
  return 0;  
}
