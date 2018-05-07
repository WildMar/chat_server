#include "common.h"
#include "server_api.h"


int main(void)
{
    int lsock = 0;
    int csock = 0;
    char buffer[MAX_BUFFER + 1];
    int ret = 0;
    
    // start server and create listening socket
    if((lsock = server_start()) == -1)
    {
        return -1;
    }
    
    // recv connection and read in message from client
    while(1)
    {
        
        if((csock = recv_connection(lsock)) == -1)
        {
            continue;    
        }
        if((ret = recv_msg(csock, buffer)) == -1)
        {
            close(csock);
            continue;
        }
        
        printf("MESSAGE: %s\n", buffer);
        memset(buffer, 0, strlen(buffer));
        //close(csock);
    }
    return 0;
}

