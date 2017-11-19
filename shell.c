#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv)
{
  char command[100];
  char exit[10] = "exit";

  while (strcmp(command, exit) != 0){
    printf("Enter command: ");
    scanf("%s", command);
    printf("You selected command %s.\n\n", command);

  }

  printf("Exiting shell\n");
  return 0;  
}
