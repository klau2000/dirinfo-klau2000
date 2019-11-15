#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  DIR *d;
  d = opendir(".");
  struct dirent *file;
  struct stat test; //used to see whether the file in the directory is a directory or a reg file
  char* regfiles[100];
  char* directories[100];

  file = readdir(d);
  while (file){
    stat(file->d_name, &test);
    char permission[100];
    sprintf(permission, "%o", test.st_mode);
    if(permission[0] == 1){

    }

    printf("%s\n", file -> d_name);
    file = readdir(d);
  }
}
