#ifndef SERVER_API_H
    #define SERVER_API_H

#define PORT_NUM 5555
#define MAX_BUFFER 1024 

int server_start();
int recv_connection(int lsock);


#endif