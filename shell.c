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
  char temp[50] = "temp";
  char cd[50]= "cd /";
  char *chwd = command + 3;

  // loop does not exit until exit command is entered
  while (strcmp(command, exit) != 0){
    printf("Enter command: ");
    fgets(command, sizeof command, stdin);
    printf("You have selected command: %s", command);

    if (strcmp(command, info) == 0){
      printf("COMP2211 Simplified Shell by sc16wyrw\n");
    }

    // gets and prints current working directory
    if (strcmp(command, pwd) == 0){
      // if working directory has been changed
      if (strcmp(cwd, temp) == 0){
        get_current_dir_name(cwd);
        printf("1) The current working directory is: %s\n", cwd);
      }
      // if working directory has not been changed
      else{
        getcwd(cwd, sizeof(cwd));
        printf("2) The current working directory is: %s\n", cwd);
      }
    }

    // changes current working directory
    if (strncmp(command, cd, 4) == 0){
      chdir(chwd);
      strcpy(cwd, chwd);
      strcpy(temp, chwd);
      printf("Switched current working directory to: %s\n", cwd);
    }

    else{
      printf("No such command found\n");
    }
  }
  printf("Exiting shell\n");
  return 0;  
}
