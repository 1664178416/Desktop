#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(){
  FILE *fp = fopen("xxx","r");
  if(fp == NULL){
    printf("errno = %d\n",errno);
    printf("error: %s\n",strerror(errno));
    perror("fopen"); //根据errno的值输出错误信息
    //提示字符串：fopen: No such file or directory
  }
  return 0;
}