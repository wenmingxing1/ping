/* gettimeofday()函数可以精确存入当前时间
 * 本程序使用gettimeofday()函数完成程序运
 * 行时间的计数
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/time.h>

//计算时间差，单位为ms
float timediff(struct timeval *begin, struct timeval *end) {
    int n;
    n = (end->tv_sec - begin->tv_sec) * 1000000 + (end->tv_usec - begin->tv_usec);

    //转化为毫秒
    return (float) (n/1000);
}

int main() {
    struct timeval begin, end;

    gettimeofday(&begin, 0);

    //程序挂起一秒
    printf("do something here...");
    sleep(1);

    gettimeofday(&end, 0);

    printf("running time is: %fms \n", timediff(&begin, &end));

    return 0;
}
