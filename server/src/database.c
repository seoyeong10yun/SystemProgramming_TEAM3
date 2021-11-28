/*
Name : database.c
function : read database or write database

*/
#pragma once

#include <stdio.h>
#include <fcntl.h>

#define database "./data/database.csv"
#define DB_U "./data/DB_user"
#define DB_C "./data/DB_Chat"
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1
FILE* fp_User; //유저 관련 파일포인터
FILE* fp_Chat; //채팅 관련 파일포인터


//extern function test
void sendData(char* userName, char* text, int responseData);

//function declare
void isPossibleName(char *userName)
{
    int fd;
    if ((fd = open(database, O_RDONLY)) == -1)
    {
        perror("Error : No database file.\n");
        exit(1);
    }
    sendData(userName, "", 0);

    close(fd);
}

void initDB(){

    fp_User=fopen(DB_U,"r+");
    fp_Chat=fopen(DB_C,"r+");

    fprintf(fp_User,"USER_NAME,USER_IP,IS_BAN\n");
    fprintf(fp_Chat,"ID,FROM,TO,CONTENT,TIME\n");

}

//구조체를 쓰면 어떨까?
void WriteName(long int user_ip, char* username,int IsBan) {
    fprintf(fp_User, "%s,%ld,%d\n", username, user_ip, IsBan);
}

void WriteMessage(long int m_id,long int From_id,long int To_id,char* content,int time) {
    fprintf(fp_Chat, "%ld,%ld,%ld,%s,%d\n", m_id, From_id, To_id, content, time);
}

// No main function in this file.
// int main(){
//     if (DEBUG)
//     {
//         printf("It runs in Debug mod.\n");
//     }

//     return 0;
// }