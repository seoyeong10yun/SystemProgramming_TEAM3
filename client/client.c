/*
Name : client.c

Prototype Goal:
program start -> show interface -> ask user_name -> sendData(name) -> receive data from server -> determine name or retry.
receive chat fron CLI(user's keyboard) -> sendData(chat)
receive chat from server -> print chat in UI

*/
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1
# include "header.h"
 
int main(int argc, char** argv)
{
    if (argc != 2) 
    {
        printf("Usage: %s IPv4-address\n", argv[0]);
        return -1;
    }
 
    struct sockaddr_in connectSocket;
 
    memset(&connectSocket, 0, sizeof(connectSocket));
 
    connectSocket.sin_family = AF_INET;
    inet_aton(argv[1], (struct in_addr*) &connectSocket.sin_addr.s_addr);
    connectSocket.sin_port = htons(PORT);
 
    int connectFD = socket(AF_INET, SOCK_STREAM, 0);
 
    if (connect(connectFD, (struct sockaddr*) &connectSocket, sizeof(connectSocket)) == -1) 
    {
        printf("Can not connect.\n");
        return -1;
    }
 
    else 
    {
        int readBytes, writtenBytes;
        char sendBuffer[BUFFER_SIZE];
        char receiveBuffer[BUFFER_SIZE];
 
        while (1) 
        {
            //서버에 문자열을 보낸 뒤 서버가 보낸 echo를 받아 출력.
            printf("서버에 보낼 말을 입력하세요 :: ");
 
            fgets(sendBuffer,BUFF_SIZE,stdin);
 
            write(connectFD, sendBuffer, strlen(sendBuffer));
            
            readBytes = read(connectFD, receiveBuffer, BUFF_SIZE);
            printf("%d bytes read\n", readBytes);
            receiveBuffer[readBytes] = '\0';
            fputs(receiveBuffer, stdout);
            fflush(stdout);
 
        }
    }
 
    close(connectFD);
    /*
    if (DEBUG){
        printf("It runs in Debug mod.\n");
    }
    */
 
    return 0;
}    