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
#define namelen 20
 
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
        char user_name[namelen] = void nameset(); // 닉네임 설정

        


 
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

// 코드 날라가서 급한대로 다시 작성하느라 테스트 못해보고 대충 틀만 잡아봤습니다
void nameset()
{
    printf("사용할 닉네임을 입력하세요 ::\n"); //사용자 닉네임 입력
    scanf("%s", user_name);
    fflush(stdin);

    write(connectFD, user_name, namelen); // 서버에 입력한 닉네임 전송

    while( namecheck = read(connectFD, receiveBuffer, BUFF_SIZE) == -1 ) // 서버에서 닉네임 중복 여부 계속 수신
        {
            printf("이미 사용 중인 닉네임입니다. 다시 입력해주십시오.\n"); // 중복시 재입력
            scanf("%s", user_name);
            fflush(stdin);
        }
    
    return user_name;
}