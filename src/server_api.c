#include "server_api.h"
#include "common.h"

int server_start()
{
    int lsock;
    int csock;
    int ret;
    int in;
    int flags;
    
    struct sockaddr_in servaddr;
    lsock = socket(AF_INET, SOCK_STREAM, 0);
    if(lsock == -1)
    {
        perror("server_start: socket()");
        return -1;
    }
 
    memset((void *)&servaddr, 0, sizeof(servaddr));
  
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT_NUM);
 
    ret = bind(lsock, (struct sockaddr *)&servaddr, sizeof(servaddr));
 
    if(ret == -1 )
    {
        perror("server_start: bind()");
        close(lsock);
        return -1;
    }
 
    ret = listen(lsock, 5);
    if(ret == -1 )
    {
        perror("server_start: listen()");
        close(lsock);
        return -1;
    }
    return lsock;

}

int recv_connection(int lsock)
{
    int len = 0;
    int csock = 0;
    printf ("Awaiting a new connection\n");

    csock = accept(lsock, (struct sockaddr *)NULL, (int *)NULL);
    if(csock == -1)
    {
        perror("recv_connection: accept()");
        close(csock);
        return -1;
    }
    else
    {
        printf ("New client connected!\n");
    }
    return csock;
    
    return 0;
}

