#include<stdio.h>
#include<unistd.h>

int main(){
  int fd[2];
  int ret = pipe(fd);
  if(ret == -1){
    perror("pipe");
  }
  printf("file dir: %d\n", fd[0]);
  long num = fpathconf(fd[0], _PC_PIPE_BUF);
  printf("PIPE_BUF: %ld\n", num);
  return 0;
}