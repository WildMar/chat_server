#include "client_api.h"
#include "common.h"

#define PORT 5555

typedef struct client
{
    int client_id;
    int sock;
}client;


int main(void)
{
    char recv_buffer[MAX_LEN];
    char send_buffer[MAX_LEN];
    int quitting = 0;
    
    int sock = 0;
    if((sock = client_start("127.0.0.1", 5555)) == -1)
    {
        return -1;
    }
    
    
    while(quitting == 0)
    {
        fgets(send_buffer, MAX_LEN, stdin);
        // get rid of newline
        send_buffer[strlen(send_buffer) - 1] = '\0';
        if(strncmp(send_buffer, "quit", strlen("quit")) == 0)
        {
            quitting = 1;
        }
        send_msg(sock, send_buffer);
        //recv_msg(sock, recv_buffer);
        //printf("RECEIVED: %s\n", recv_buffer);
        
    }
    
}

//int client_start(chat_client *client, struct sockaddr_in *serv_addr)
