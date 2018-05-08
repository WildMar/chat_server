#include "common.h"
#include "server_api.h"


#define NUM_THREADS 5
// server should:
// handle multiple connections
// echo messages from one connection to all connections
// maintain profiles for clients
// store history of chat

int process_connection(Server *chat_server)
{
    int ret = 0;
    char buffer[MAX_BUFFER + 1];
    recv_connection(chat_server);
    printf("Socket: %d\n", chat_server->csock);
    if(chat_server->csock == -1)
    {
        printf("Exiting\n");
        close(chat_server->csock);
        pthread_exit(NULL);
        return 0;
    }
    
    while((ret = recv_msg(chat_server->csock, buffer)) > 0)
    {
        printf("MESSAGE: %s\n", buffer);
        if(strncmp(buffer, "quit", strlen("quit")) == 0)
        {
            close(chat_server->csock);
            memset(buffer, 0, strlen(buffer));
            break;
        }
        memset(buffer, 0, strlen(buffer));    
    }
    printf("Exiting..");
    close(chat_server->csock);
    pthread_exit(NULL);
}


int main(void)
{

    int ret = 0;
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    Server *chat_server = malloc(sizeof(Server));
    
    // start server and create listening socket
    server_start(chat_server);
    if(chat_server->lsock == -1)
    {
        free(chat_server);
        return -1;
    }
    
    // recv connection and read in message from client
        // upon receiving a connection, spin off a thread to
        // receive data from client while waiting for
        // more connections

    for(t = 0; t < NUM_THREADS; t++)
    {
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, 
                            process_connection, 
                            (void *)chat_server);
        if(rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
        //close(csock);
    /* Last thing that main() should do */
    pthread_exit(NULL);
    free(chat_server);
    return 0;
}

