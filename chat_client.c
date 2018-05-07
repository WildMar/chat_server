
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#define MAX_LEN 1024
#define PORT_NUM 5555


int main(void)
{
    struct sockaddr_in address;
    int sock = 0;
    struct sockaddr_in serv_addr;
    char recv_buffer[MAX_LEN];
    char send_buffer[MAX_LEN];
    int bytes_read = 0;
    
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket()");
        return -1;
    }
  
    memset(&serv_addr, 0, sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT_NUM);
      
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        perror("inet_pton()");
        return -1;
    }
  
    if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect()");
        return -1;
    }
    
    fgets(send_buffer, MAX_LEN, stdin);
    
    send(sock, send_buffer, strlen(send_buffer) , 0 );
    printf("Message sent\n");
    bytes_read = read(sock, recv_buffer, MAX_LEN);
    printf("%s\n", recv_buffer);
    
    return 0;
}

