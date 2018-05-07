#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT_NUM 5555
#define MAX_BUFFER 1024 
 
int main(void)
{
    int lsock;
    int csock;
    int ret;
    int in;
    int flags;
    
    struct sockaddr_in servaddr;
    char buffer[MAX_BUFFER + 1];
 
    lsock = socket(AF_INET, SOCK_STREAM, 0);
    if(lsock == -1)
    {
        perror("socket()");
        return -1;
    }
 
    memset((void *)&servaddr, 0, sizeof(servaddr));
  
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT_NUM);
 
    ret = bind(lsock, (struct sockaddr *)&servaddr, sizeof(servaddr));
 
    if(ret == -1 )
    {
        perror("bind()");
        close(lsock);
        return -1;
    }
 
    ret = listen(lsock, 5);
    if(ret == -1 )
    {
        perror("listen()");
        close(lsock);
        return -1;
    }
 
    while(1)
    {
        int len;
        memset(buffer, 0, MAX_BUFFER + 1);
 
        printf ("Awaiting a new connection\n");
 
        csock = accept(lsock, (struct sockaddr *)NULL, (int *)NULL);
        if(csock == -1)
        {
            perror("accept()");
            close(csock);
            continue;
        }
        else
        {
            printf ("New client connected!\n");
        }
 
        in = read(csock, buffer, sizeof(buffer));
 
        if(in == -1)
        {
            perror("sctp_recvmsg()");
            close(csock);
            continue;
        }
        else
        {
            buffer[in] = '\0';
 
            printf ("Data len: %d\n", in);
            printf ("Msg: %s\n", (char *)buffer);
        }
        close(csock);
    }
 
    return 0;
}