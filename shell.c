#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv)
{
  char command[100];
  char exit[10] = "exit";
  char info[10] = "info";

  while (strcmp(command, exit) != 0){
    printf("Enter command: ");
    scanf("%s", command);
    printf("You selected command %s.\n", command);

    if (strcmp(command, info) == 0){
      printf("COMP2211 Simplified Shell by sc16wyrw\n\n");
    }
  }

  printf("Exiting shell\n");
  return 0;  
}
