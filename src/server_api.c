#include "server_api.h"
#include "common.h"

int server_start(Server *new_server)
{
    int ret;
    int in;
    int flags;
    
    struct sockaddr_in servaddr;
    new_server->lsock = socket(AF_INET, SOCK_STREAM, 0);
    if(new_server->lsock == -1)
    {
        perror("server_start: socket()");
        return -1;
    }
 
    memset((void *)&servaddr, 0, sizeof(servaddr));
  
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT_NUM);
 
    ret = bind(new_server->lsock, (struct sockaddr *)&servaddr, 
                sizeof(servaddr));
 
    if(ret == -1 )
    {
        perror("server_start: bind()");
        close(new_server->lsock);
        return -1;
    }
 
    ret = listen(new_server->lsock, 5);
    if(ret == -1 )
    {
        perror("server_start: listen()");
        close(new_server->lsock);
        return -1;
    }
    return 0;

}

int recv_connection(Server *server)
{
    printf ("Awaiting a new connection\n");

    server->csock = accept(server->lsock, 
                            (struct sockaddr *)NULL, 
                            (int *)NULL);
    if(server->csock == -1)
    {
        perror("recv_connection: accept()");
        close(server->csock);
        return -1;
    }
    else
    {
        printf ("New client connected!\n");
    }
    
    return 0;
}

