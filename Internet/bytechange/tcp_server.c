#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>

int main(){
  //创建tcp服务器
  //创建套接字
  int lfd = socket(AF_INET,SOCK_STREAM,0);
  //绑定地址
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8082);
  inet_pton(AF_INET,"192.168.80.255",&addr.sin_addr.s_addr); 
  int ret = bind(lfd,(struct sockaddr*)&addr,sizeof(addr));
  if(ret < 0){
    perror("bind error");
    return -1;
  }
  //监听
  listen(lfd,128);
  //提取，接受连接
  struct sockaddr_in client_addr;  //客户端地址
  socklen_t len = sizeof(client_addr); //地址长度
  int cfd = accept(lfd,(struct sockaddr*)&client_addr,&len); //返回一个新的套接字，用于和客户端通信
  //读写数据

  char ip[16] = "";
  printf("new client: ip = %s port = %d\n",inet_ntop(AF_INET,&client_addr.sin_addr.s_addr,ip,16),ntohs(client_addr.sin_port));

  char buf[1024] = "";
  while(1){
    bzero(buf,sizeof(buf));
    int n = read(STDERR_FILENO,buf,1024); //从标准输入读取数据
    write(cfd,buf,n); //写入套接字，发送数据给客户端
    n = read(cfd,buf,1024); //从套接字读取数据
    write(STDOUT_FILENO,buf,n); //写入到标准输出
  }
  close(lfd); //不再接受连接
  close(cfd); //只是断开当前连接
  return 0;
}