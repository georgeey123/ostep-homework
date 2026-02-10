#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char *argv[]){

  int rc = fork();

  if (rc < 0){
    fprintf(stderr, "failed to fork\n");
    exit(1);
  } else if (rc == 0){
    printf("printing from child\n");
  } else{
    wait(NULL);
    printf("did child close first?");
  }

  return 0;
}
