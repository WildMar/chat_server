#include "common.h"

#define MAX_LEN 1024


int send_msg(int sock, char *send_buffer)
{
    send(sock, send_buffer, strlen(send_buffer), 0 );
    printf("Message sent: %s\n", send_buffer);
    return 0;
}


int recv_msg(int sock, char *recv_buffer)
{
    memset(recv_buffer, 0, MAX_LEN + 1);
    int bytes_read = 0;
    bytes_read = read(sock, recv_buffer, MAX_LEN);
    printf("bytes read: %d\n", bytes_read);
    if(bytes_read == -1)
    {
        perror("recv_msg: read()");
        return -1;
    }
    else
    {
        recv_buffer[bytes_read] = '\0';
    }
    return 0;
}