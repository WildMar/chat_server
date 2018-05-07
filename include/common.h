#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAX_LEN 1024

int recv_msg(int sock, char *recv_buffer);
int send_msg(int sock, char *send_buffer);

#endif