#include<stdio.h>
#include<sys/time.h>
#include <signal.h> // Include the <signal.h> header file
#include <unistd.h> // Include the <unistd.h> header file
// int main(){
//     int seconds = 0;
//     seconds = alarm(5);
//     printf("Seconds remaining: %d\n", seconds);

//     sleep(2);
//     seconds = alarm(5);
//     printf("Seconds remaining: %d\n", seconds);
    
//     while(1);
//     return 0;
// }

void myfunc(int sig)
{
    printf("hello\n");
}
int main()
{
    struct itimerval new_value;
    //定时周期
    new_value.it_interval.tv_sec = 1;
    new_value.it_interval.tv_usec = 0;
    //第一次触发的时间
    new_value.it_value.tv_sec = 2;
    new_value.it_value.tv_usec = 0;
    int second = 0;
    second = alarm(5);
    printf("Seconds remaining: %d\n", second);
    signal(SIGALRM, myfunc); //信号处理
    setitimer(ITIMER_REAL, &new_value, NULL); //定时器设置
    while (1);
    return 0;
}