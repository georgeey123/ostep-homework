#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]){
  
  int fd = open("./q2_tmp.txt", O_RDWR); 
  
  if (fd == -1){
    fprintf(stderr,"failed to open file");
  }

  int rc = fork();

  if (rc < 0){
    fprintf(stderr, "fork failed\n");
  } else if (rc ==0){
    
    printf("file descriptor from child: %d\n", fd);

    printf("writing to opened via child file\n");
    
    const char *text = "writing from child process to file";
    ssize_t bytesWritten = write(fd, text, strlen(text));
    
    if (bytesWritten == -1){
      fprintf(stderr, "Error writing to file from child\n");
      close(fd);
    }

    printf("successfully wrote %zd bytes to the file via child.\n", bytesWritten);
    close(fd);
    
  } else{
    printf("file descriptor from parent %d\n", fd);

    printf("writing to opened file from parent\n");

    const char *text = "writing from parent to file\n";
    ssize_t bytesWritten = write(fd, text, strlen(text));

    if (bytesWritten == -1){
      fprintf(stderr, "error writing to file form parent");
      close(fd);
    }
  }

  return 0;
}

