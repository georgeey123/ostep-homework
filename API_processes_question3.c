#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]){

  printf("start of the program: question 3\n");
  int rc = fork();
  
  if (rc < 0){
    fprintf(stderr, "failed to fork\n");
  }else if (rc == 0){
    printf("hello (from child)\n");
  }else{
    sleep(1);
    printf("goodbye (from parent)\n");
  }

  return 0;
}
