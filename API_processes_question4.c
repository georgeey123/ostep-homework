#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
  
  int rc = fork();

  if (rc < 0){
    fprintf(stderr, "failed to fork process\n");
    exit(1);
  } else if (rc == 0){
    char *myargs[2];

    myargs[0] = strdup("ls");
    myargs[1] = NULL;

    execvp(myargs[0], myargs);
  } else{
    printf("result of ls: \n");
  }

  return 0;
}
