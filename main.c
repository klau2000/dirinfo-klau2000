#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "dir.h"

int main(int argc, char *argv[]) {
  struct dirent *file;
  struct stat test; //used to see if the file is a directory or regular file
  long totalsize;

  DIR *d;
  char input[100];
  if(argc == 1){ //tests to see if a file was already inputted in the command line
    printf("Please enter in a directory name:\n");
    fgets(input, sizeof input, stdin);
    input[strlen(input) - 1] = '\0';
    d = opendir(input);
  }
  else {
    d = opendir(argv[1]);
  }
  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
    printf("Error message: %s\n", strerror(errno));
  }

  file = readdir(d);
  while (file){ //reads through the file
    stat(file->d_name, &test);
    char permission[100];
    sprintf(permission, "%o", test.st_mode);
    if(permission[0] == '4'){ //if a directory...
        printf("%-20s\t Type: Directory\n", file -> d_name);
    }
    if(permission[0] == '1'){ //if a regular file...
        printf("%-20s\t Type: Regular File\n", file -> d_name);
        totalsize += test.st_size;
        printf("%d\n", totalsize);
    }
    file = readdir(d);
  }
printf("%d\n", totalsize);
readable(totalsize);
}
