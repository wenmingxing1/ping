#include<stdio.h>
#include<arpa/inet.h>

int main() {
    unsigned short hosts = 0x1234;
    unsigned short nets;
    unsigned long hostl = 0x12345678;
    unsigned long netl;

    nets = htons(hosts);
    netl = htonl(hostl);

    printf("Host ordered short: %#x \n", hosts);  //主机字节为小端序
    printf("Network ordered short: %#x \n", nets);
    printf("Host ordered long: %#lx \n", hostl);
    printf("Network ordered long: %#lx \n", netl);

    return 0;
}
