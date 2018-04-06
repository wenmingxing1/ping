/* gethostbyname函数可以根据域名获取IP地址
 * 成功时返回如下结构体
*/

/*
 
struct hostent {
    char* h_name;
    char** h_aliases;
    char h_addrtype;
    char h_length;
    char** h_addr_list;     //存储IP地址
}

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>

int main(int argc, char* argv[]) {
    int i;
    struct hostent *host;

    if (argc < 2) {
        printf("Use: %s <hostname> \n", argv[0]);
        exit(1);
    }

    host = gethostbyname(argv[1]);

    for (i = 0; host->h_addr_list[i]; ++i) {
        printf("IP addr %d : %s \n", i+1, inet_ntoa(*(struct in_addr *)host->h_addr_list[i]));
    }

    return 0;
}
