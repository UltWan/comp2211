#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define token_args " \t\r\n"

int main(int argc, char **argv)
{
  char *command;
  char input[100];
  char cwd[100];

  // infinite loop for shell
  while (true){
    printf("Enter command: ");
    fgets(input, 100, stdin);
    // splits string into command as first part
    command = strtok(input, token_args);

      // exits loop command is exit
      if (strcmp(command, "exit") == 0){
        break;
      }

      // prints basic info
      else if (strcmp(command, "info") == 0){
        printf("COMP2211 Simplified Shell by sc16wyrw\n");
      }

      // gets and prints current working directory
      else if (strcmp(command, "pwd") == 0){
        printf("The current working directory is:%s\n", getcwd(cwd, sizeof(cwd)));
      }

      // changes current working directory and prints out current one
      else if (strcmp(command, "cd") == 0) {
        char *path = strtok(0, token_args);

        if (path == NULL){
          printf("Error: No path specified.\n");
        }
        else{
          chdir(path);
          printf("The current working directory is:%s\n", (getcwd(cwd, sizeof(cwd))));
        }
      }

      // executes filepath
      else if (strcmp(command, "ex") == 0) {
        char *path = strtok(0, token_args);

        if (path == NULL){
          printf("Error: No path specified.\n");
        }
        else{
          chdir(path);
          printf("The current working directory is:%s\n", (getcwd(cwd, sizeof(cwd))));
        }
      }

      else{
        printf("No such command found\n");
      }
    
  }
  printf("Exiting shell\n");
  return 0;  
}
