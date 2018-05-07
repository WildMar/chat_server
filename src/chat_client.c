
#include "common.h"

#define PORT 5555

typedef struct chat_client
{
    int client_id;
    int sock;
}chat_client;


int main(void)
{
    client_start();    
    
}

//int client_start(chat_client *client, struct sockaddr_in *serv_addr)
int client_start()
{
    char recv_buffer[MAX_LEN];
    int sock = 0;
    struct sockaddr_in serv_addr;
    
    
    memset(&serv_addr, 0, sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        return -1;
    }
  
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket()");
        return -1;
    }
  
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect()");
        return -1;
    }
    
    while(1)
    {
        send_msg(sock, "WHY HELLO THAR");
        recv_msg(sock, recv_buffer);
        printf("RECEIVED: %s\n", recv_buffer);
        
    }
    return 0;
}
