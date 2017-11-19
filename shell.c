#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  char command[50];
  char exit[5] = "exit";
  char info[5] = "info";
  char pwd[4]= "pwd";
  char cwd[50];

  while (strcmp(command, exit) != 0){
    printf("Enter command: ");
    scanf("%s", command);
    printf("You have selected command %s.\n", command);

    if (strcmp(command, info) == 0){
      printf("COMP2211 Simplified Shell by sc16wyrw\n\n");
    }

    if (strcmp(command, pwd) == 0){
      getcwd(cwd, sizeof(cwd));
      printf("The current working directory is: %s\n", cwd);
    }
  }

  printf("Exiting shell\n");
  return 0;  
}
