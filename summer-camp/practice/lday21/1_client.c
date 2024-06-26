#include <func.h>

int main(int argc, char* argv[])
{
    // ./1_client 192.168.68.128 1234
    //socket 是两端通信的端点
    ARGS_CHECK(argc, 3);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    ERROR_CHECK(ret, -1, "connect");
    sleep(5);
    printf("sleep over\n");
    ssize_t sret = send(sockfd, "hello", 5, 0);
    printf("sret = %ld\n", sret);
    sret = send(sockfd, "world", 5, 0);
    //sret = write(sockfd, "world", 5);
    printf("sret = %ld\n", sret);
    return 0;
}

