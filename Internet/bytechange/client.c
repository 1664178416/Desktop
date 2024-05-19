#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>

int main(int argc,char* argv[]){
  //创建套接字
  int sock_fd;
  sock_fd = socket(AF_INET,SOCK_STREAM,0);
  //连接服务器
  struct sockaddr_in addr; //专门的ipv4地址结构
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  inet_pton(AF_INET,"192.168.80.1",&addr.sin_addr.s_addr);
  connect(sock_fd,(struct sockaddr*)&addr,sizeof(addr)); //连接服务器，服务器地址为addr，使用通用地址结构
  //读写数据
  char buf[1024] = "";
  while(1){
    int n = read(STDIN_FILENO,buf,1024); //从标准输入读取数据
    write(sock_fd,buf,n); //写入套接字,发送数据给服务器

    //从服务器读数据
    int m = read(sock_fd,buf,1024); //从套接字读取数据 
    write(STDOUT_FILENO,buf,m); //写入到标准输出
  }

  //关闭套接字
  close(sock_fd);
}