#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

#define TOKEN_ARGS " \t\n"

  char *command;
  char input[100];
  char cwd[100];

int main(int argc, char **argv)
{
  // infinite loop for shell
  while (true){
    printf("$: ");
    fgets(input, 100, stdin);
    // splits string into command as first part
    command = strtok(input, TOKEN_ARGS);

      const char *path = strtok(0, TOKEN_ARGS);

      // checks empty input
      if (command == NULL){
        printf("Error: No command entered\n");
      }

      // exits loop command is exit
      else if (strcmp(command, "exit") == 0){
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
        //const char *path = strtok(0, TOKEN_ARGS);

        if (path == NULL){
          perror("$");
        }
        else{
          chdir(path);
          printf("The current working directory is:%s\n", (getcwd(cwd, sizeof(cwd))));
        }
      }

      // executes program in filepath
      else if (strcmp(command, "ex") == 0) {
        //const char *path = strtok(0, TOKEN_ARGS);

        if (path == NULL){
          printf("Error: No path specified.\n");
        }

        else{
          pid_t child, parent;
          int status;

          child = fork();
          if (child == 0) {
          // Child process
            if (execvp(path, argv[1]) == -1) {
              perror("$");
            }
            exit(EXIT_FAILURE);
          } 
          else if (child < 0) {
          // Error forking
            perror("$");
          }
          else {
          // Parent process
            do {
              parent = waitpid(child, &status, WUNTRACED);
            } 
            while (!WIFEXITED(status) && !WIFSIGNALED(status));
          }
        }
      }

      // see what files are in the current directory
      else if (strcmp(command, "ls") == 0){
        system("ls");
      }

      else{
        printf("Error: Invalid command entered\n");
      }
    
  }
  printf("Exiting shell\n");
  return 0;  
}

// /home/ryan/Desktop/coding/comp1711/assignment_01/timetable > a.txt
// /home/ryan/Desktop/coding/comp1711/assignment_03/textbanners
// /home/csunix/sc16wyrw/comp1711/sc16wyrw/assignment_03/textbanners
