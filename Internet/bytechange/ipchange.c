#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<arpa/inet.h>

int main(){
  char buf[] = "192.168.1.2"; //低字节为2，高字节为192
  unsigned int name = 0;
  inet_pton(AF_INET,buf,&name);  //将点分十进制转换为网络字节序,大端存储，发送时用的多
  printf("name = %d\n",name);
  unsigned char* p = (unsigned char*) &name;
  printf("%d,%d,%d,%d\n",*p,*(p+1),*(p+2),*(p+3)); //大端存储
  char ip[16] = "";
  inet_ntop(AF_INET,&name,ip,16); //将网络字节序转换为点分十进制  ，接收时用的多
  printf("%s",ip);
}