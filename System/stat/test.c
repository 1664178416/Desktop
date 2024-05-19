#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
  int ret = -1;
  struct  stat s;
  //获取指定文件信息
  ret = stat("1.txt",&s);
  if(ret == -1){
    perror("stat");
    exit(1);
  }
  printf("文件大小：%ld\n",s.st_size);
  printf("文件类型：%d\n",s.st_mode);
  printf("st_dev:%lu\n",s.st_dev);
  printf("st_uid:%d\n",s.st_uid);
  return 0;
}