#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dir.h"

void readable(long size) {
  int count = 0;
  while (size >= 1000) {
    size = size / 1000;
    count += 1;
    if (count == 3) {
      break;
    }
  }
  if (count == 0) {
    printf("Readable Size of Regular Files: %ldB\n", size);
  }
  if (count == 1) {
    printf("Readable Size of Regular Files:%ldKB\n", size);
  }
  if (count == 2){
    printf("Readable Size of Regular Files:%ldMB\n", size);
  }
  if (count == 3){
    printf("Readable Size of Regular Files:%ldGB\n", size);
  }
}
