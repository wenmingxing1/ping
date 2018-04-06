/*IP,ICMP,UDP,TCP都有校验和字段，其计算方式都是一样的
 * 二进制取反求和，只不过ICMP对首部和报文数据一起计算
 * 而IP，UDP，TCP，只计算首部字段
*/

//由于16位相加可能回产生仅为，所以用32位来保存结果

usigned short checkSum(unsigned short *addr, int len) {
    usigned int sum = 0;
    while (len > 1){
        sum += *addr++;
        len -= 2;
    }

    //处理剩下一个字节
    if (len == 1)
        sum += *(unsigned char*)addr;

    //将32位的高16位与低16位相加
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);

    return (unsigned short) ~sum;
}
