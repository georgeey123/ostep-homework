#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  int x = 1;

  int temp = x + 99;
  printf("Value before fork: %d", temp);
  int rc = fork();
  
  if (rc < 0){
    fprintf(stderr, "fork failed\n");
  } else if (rc == 0){
    temp = 300;
    printf("value after fork: %d\n", temp);
  } else{
    temp = 200;
    printf("parent, temp is: %d\n", temp);
  }

  return 0;
  
}


