/* inet_ntoa函数将32位大端序整型IP地址格式转化为点分十进制格式;*/

#include<stdio.h>
#include<arpa/inet.h>

int main() {
    struct in_addr addr1, addr2;

    char *str1, *str2;

    addr1.s_addr = htonl(0x1020304);
    addr2.s_addr = htonl(0xc0a80101);

    str1 = inet_ntoa(addr1);
    str2 = inet_ntoa(addr2);

    printf("%#lx -> %s \n", (long)addr1.s_addr, str1);
    printf("%#lx -> %s \n", (long)addr2.s_addr, str2);

    return 0;
}
