#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirinfo.h"

int main() {
  struct dirent *file;
  struct dirent *file2;
  struct stat test; //used to see whether the file in the directory
  long totalsize;

  DIR *d;
  d = opendir(".");
  file = readdir(d); //reading for directories
  if(errno){ //see if any error
   printf("Error number: %d\n", errno);
  }

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
 readable(totalsize);
}
