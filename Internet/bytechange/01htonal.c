#include<arpa/inet.h>
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char* argv[]){
  char buf[4] = {192,168,1,2}; //小端存储 buf[0],buf[1],buf[2],buf[3]字节和地址依次增加 
  int num = *(int*)buf; 
  printf("num = %d\n",num);
  unsigned int sum = htonl(num);
  unsigned char* p = (unsigned char*) &sum;
  printf("sum = %lld\n",(long long)sum);
  printf("%d,%d,%d,%d\n",*p,*(p+1),*(p+2),*(p+3)); //大端存储
  return 0;
}