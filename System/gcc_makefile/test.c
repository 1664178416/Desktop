#include<stdio.h>
#include "add.h"
#include "mul.h"
#include "div.h"
#include "sub.h"

int main(){
  int x = 15;
  int y = 5;
  printf("Addition of %d and %d is %d\n",x,y,add(x,y));
  printf("Multiplication of %d and %d is %d\n",x,y,mul(x,y));
  printf("Division of %d and %d is %d\n",x,y,div(x,y));
  printf("Subtraction of %d and %d is %d\n",x,y,sub(x,y));
  printf("hello,world\n");
  return 0;
}