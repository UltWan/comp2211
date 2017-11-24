#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>

#define TOKEN_ARGS " \t\r\n"

  char *command;
  char input[100];
  char cwd[100];

int main(int argc, char **argv)
{
  // infinite loop for shell
  while (true){
    printf("Enter command: ");
    fgets(input, 100, stdin);
    // splits string into command as first part
    command = strtok(input, TOKEN_ARGS);

      if (command == NULL){
        printf("No command entered\n");
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
        const char *path = strtok(0, TOKEN_ARGS);

        if (path == NULL){
          perror("Error: No path specified.\n");
        }
        else{
          chdir(path);
          printf("The current working directory is:%s\n", (getcwd(cwd, sizeof(cwd))));
        }
      }

      // executes filepath
      else if (strcmp(command, "ex") == 0) {
        const char *path = strtok(0, TOKEN_ARGS);
        int status;

        if (path == NULL){
          printf("Error: No path specified.\n");
        }
        else{
          pid_t pid, wpid;
          int status;

          pid = fork();
          if (pid == 0) {
          // Child process
            if (execvp(path, argv[1]) == -1) {
              perror("lsh");
            }
            exit(EXIT_FAILURE);
          } 
          else if (pid < 0) {
          // Error forking
            perror("lsh");
          }
          else {
          // Parent process
            do {
              wpid = waitpid(pid, &status, WUNTRACED);
            } 
            while (!WIFEXITED(status) && !WIFSIGNALED(status));
          }
        }
      }

      // executes background process
      else if (strcmp(command, "exb") == 0) {
        const char *path = strtok(0, TOKEN_ARGS);
        int status;

        if (path == NULL){
          printf("Error: No path specified.\n");
        }
        else{
          pid_t pid, wpid;
          int status;

          pid = fork();
          if (pid == 0) {
          // Child process
            if (execvp(path, argv[1]) == -1) {
              perror("lsh");
            }
            exit(EXIT_FAILURE);
          } 
          else if (pid < 0) {
          // Error forking
            perror("lsh");
          }
          else {
          // Parent process
            do {
              wpid = waitpid(pid, &status, WUNTRACED);
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
        printf("No such command exists\n");
      }
    
  }
  printf("Exiting shell\n");
  return 0;  
}

//ex /home/csunix/sc16wyrw/comp1711/sc16wyrw/assignment_03/textbanners
