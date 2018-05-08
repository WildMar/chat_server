#include "client_api.h"
#include "common.h"

#define PORT 5555

typedef struct chat_client
{
    int client_id;
    int sock;
}chat_client;


int main(void)
{
    char recv_buffer[MAX_LEN];
    char send_buffer[MAX_LEN];
    
    int sock = 0;
    if((sock = client_start("127.0.0.1", 5555)) == -1)
    {
        return -1;
    }
    
    
    while(1)
    {
        fgets(send_buffer, MAX_LEN, stdin);
        // get rid of newline
        send_buffer[strlen(send_buffer) - 1] = '\0';
        send_msg(sock, send_buffer);
        //recv_msg(sock, recv_buffer);
        //printf("RECEIVED: %s\n", recv_buffer);
        
    }
    
}

//int client_start(chat_client *client, struct sockaddr_in *serv_addr)
