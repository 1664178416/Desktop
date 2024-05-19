#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/mman.h> // Include the necessary header file
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main(){
  int fd = open("test.txt", O_RDWR); //打开文件
  int len = 20; //获取文件大小
  printf("the size of file:%d\n",len);
  //创建内存映射区
  void *ptr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  if(ptr == MAP_FAILED){
    perror("mmap");
    exit(1);
  }
  close(fd); //关闭文件

  //子进程
  pid_t pid = fork();
  if(pid == 0){
    sleep(1); //保证父进程先执行
    //读数据
    printf("%s\n",(char*)ptr);
  }
  //父进程
  else if(pid > 0){
    //写数据
    strcpy((char*)ptr,"hello,world,i am u father");
    //等待子进程结束
    wait(NULL);
  }

  //释放内存映射区——只有父进程能走到这里
  int ret = munmap(ptr,len);
  if(ret == -1){
    perror("munmap");
    exit(1);
  }
  return 0;
}