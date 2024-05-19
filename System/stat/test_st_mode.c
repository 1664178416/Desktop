#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int show_file_type(struct  stat *s){
  #include <sys/stat.h>

  switch (s->st_mode & S_IFMT)
  {
    case __S_IFREG:
      printf("普通文件\n");
      break;
    case __S_IFDIR:
      printf("目录文件\n");
      break;
    case __S_IFCHR:
      printf("字符设备文件\n");
      break;
    case __S_IFBLK:
      printf("块设备文件\n");
      break;
    case __S_IFIFO:
      printf("FIFO文件\n");
      break;
    case __S_IFLNK:
      printf("符号链接文件\n");
      break;
    case __S_IFSOCK:
      printf("套接字文件\n");
      break;
    default:
      printf("未知文件类型\n");
      break;
  }
  return 0;
}

int main(int argc,char **argv){
  int ret = -1;
  struct stat s;
  //容错判断
  if(argc != 2){
    printf("Usage: %s <file>\n",argv[0]);
    return 1;
  }
  //获取指定文件信息
  ret = stat(argv[1],&s);
  if(ret == -1){
    perror("stat");
    exit(1);
  }
  //显示文件类型q
  show_file_type(&s);
}

