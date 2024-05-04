#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void func(){
    int i = 0;
    for(i = 0;i < 10;i++){
	printf("i = %d\n",i);	
    }
    vector<int> a = {1,2,3};
    for(i = 0;i<a.size();i++){
        printf("vector[%d]:%d",i,a[i]);
        cout << " " << a[i] << endl;
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
