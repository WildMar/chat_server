#ifndef SERVER_API_H
    #define SERVER_API_H

#define PORT_NUM 5555
#define MAX_BUFFER 1024 

typedef struct server
{
    int lsock;
    int csock;
}Server;



int server_start(Server *new_server);
int recv_connection(Server *server);


#endif