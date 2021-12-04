/*
Name : database.c
function : read database or write database

*/

#include <stdio.h>
#include <fcntl.h>

#define database "./data/database.csv"
#define DB_U "./data/DB_user.csv"
#define DB_C "./data/DB_Chat.csv"
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1
FILE* fp_User; //유저 관련 파일포인터
FILE* fp_Chat; //채팅 관련 파일포인터

typedef struct userData
{
    int user_ip;
    char user_name[512];
}user_data;

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
    //test
    if (DEBUG)
    {
	
        WriteName(123, userName, 0);
	
        //sendData(userName, "", 0);
    }

    close(fd);
}

/*
프로그램을 처음 시작할 때 사용.
csv파일의 첫번째 줄을 적는다.
*/
void initDB(){
    fp_User=fopen(DB_U,"w+");
    fp_Chat=fopen(DB_C,"w+");

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

/*
No main function in this file.
int main(){
    if (DEBUG)
    {
        printf("It runs in Debug mod.\n");


    }
    return 0;
}
*/
