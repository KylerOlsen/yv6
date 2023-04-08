/*
  Kyler Olsen
  touch
  April 2023
*/

#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  int fd, i;

  if(argc <= 1) {
    exit(0);
  }

  for(i = 1; i < argc; i++) {
    if((fd = open(argv[i], O_CREATE)) < 0) {
      fprintf(2, "touch: cannot create %s\n", argv[i]);
      exit(1);
    }
    close(fd);
  }
  exit(0);
}