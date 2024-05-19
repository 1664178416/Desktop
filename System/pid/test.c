#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>

int a = 20;
int main()
{
    printf("hello,world");
    fflush(stdout);
    _exit(0);
}