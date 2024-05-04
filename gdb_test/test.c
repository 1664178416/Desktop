#include<stdio.h>

void func(){
    int i = 0;
    for(i = 0;i < 10;i++){
	printf("i = %d\n",i);	
    }
}


int main(int argc,char **argv){
    int i = 0;

    for(i = 0;i < argc;i++){
    	printf("argv[%d]:%s\n",i,argv[i]);
    }

    func();

    printf("hello itcast\n");

    return 0;

}
