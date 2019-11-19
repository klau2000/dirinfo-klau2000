#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
//#include "dir.h"

int main(int argc, char *argv[]) {
  struct dirent *file;
  struct dirent *file2;
  struct stat test; //used to see whether the file in the directory
  long totalsize;

  DIR *d;
  char input[100];
  if(argc == 1){
    printf("Please enter in a directory name:\n");
    fgets(input, sizeof input, stdin);
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
  while (file){
    stat(file->d_name, &test);
    char permission[100];
    sprintf(permission, "%o", test.st_mode);
    if(permission[0] == '4'){
        printf("%-20s\t Type: Directory\n", file -> d_name);
    }
    if(permission[0] == '1'){
        printf("%-20s\t Type: Regular File\n", file -> d_name);
        totalsize += test.st_size;
    }
    file = readdir(d);
  }
// readable(totalsize);
}
