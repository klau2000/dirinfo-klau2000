#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
  struct dirent *file;
  struct dirent *file2;
  struct stat testd; //used to see whether the file in the directory
  struct stat testr;
  //char* regfiles[100];
  //char* directories[100];
  DIR *d;
  d = opendir(".");
  file = readdir(d); //reading for directories
  if(errno){ //see if any error
   printf("Error number: %d\n", errno);
  }

  while (file){
    stat(file->d_name, &testd);
    char permission[100];
    sprintf(permission, "%o", testd.st_mode);
    if(permission[0] == '4'){
        printf("%-20s\t Type: Directory\n", file -> d_name);
    }
    if(permission[0] == '1'){
        printf("%-20s\t Type: Regular File\n", file -> d_name);
    }
    file = readdir(d);
  }

}
