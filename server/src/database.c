/*
Name : database.c

Prototype Goal:
server initDB() -> make file or stay.
server isPossibleName() -> search DB -> {write data in DB and sendData(success)} or sendData(error)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define DB_USER "./data/DB_User.csv"
#define DB_CHAT "./data/DB_Chat.csv"
#define DB_DELIMITER ","
#define TRUE 1
#define FALSE 0
#define DEBUG 0 //when debugging, set value 1
FILE *fp_user;  //유저 관련 파일포인터
FILE *fp_chat;  //채팅 관련 파일포인터

//test user data struct
typedef struct userData
{
    int user_ip;
    char user_name[512];
} user_data;

//extern function test
void sendData(char *user_name, char *user_text, int response_data);

//function declare
void isPossibleName(char *user_name);
const char* getField(char* line , int num);
void initDB();
void WriteName(long int user_ip, char *user_name, int is_ban);
void WriteMessage(long int m_id, long int from_id, long int to_id, char *user_text, int cur_time);


/*
이름을 입력받고 이름의 사용 가능 여부를 클라이언트로 전송하는 함수
input : char* name
output : char* name, char* void, bool ispossible
return : 
*/
void isPossibleName(char *user_name)
{
    int i, j, k;

    fp_user = fopen(DB_USER, "r+");
    if (fp_user == NULL)
    {
        perror("Error : No database file.\n");
        fclose(fp_user);
        exit(1);
    }

    //search DB
    short int check_name_exist = 0;
    char one_line_string[128];
    char* db_name_string;

    while(fgets(one_line_string, 128, fp_user)){
        char* tmp = strdup(one_line_string);
        db_name_string = getField(tmp, 1);
        if(strcmp(db_name_string, user_name) == 0){
            check_name_exist = 1;
            break;
        }
        free(tmp);
    }
    
    //return result
    if (check_name_exist)
    {
        printf("Result : %s is already in the DB.\n", user_name);
    }
    else {
        fprintf(fp_user, user_name);
        fprintf(fp_user, DB_DELIMITER);
        fprintf(fp_user, "test_ip");
        fprintf(fp_user, DB_DELIMITER);
        fprintf(fp_user, "test_is_ban");
        fprintf(fp_user, "\n");
        printf("Result : %s registers to DB.\n", user_name);
    }
    fclose(fp_user);
}
/*

*/
const char* getField(char line[], int num){
    const char * tok;
    for(tok = strtok(line, DB_DELIMITER); tok && *tok; tok = strtok(NULL, ",\n")){
        if(!--num){
            return tok;
        }
    }
    return NULL;
}
 
/*
프로그램을 처음 시작할 때 사용.
csv파일의 첫번째 줄, 유저 데이터 항목을 적는다.
input : 
output : 
return : 
*/
void initDB()
{
    remove(DB_USER);
    remove(DB_CHAT);

    fp_user = fopen(DB_USER, "w+");
    fp_chat = fopen(DB_CHAT, "w+");

    fprintf(fp_user, "USER_NAME,USER_IP,IS_BAN\n");
    fprintf(fp_chat, "ID,FROM,TO,CONTENT,TIME\n");
    
    if(DEBUG){
        fprintf(fp_user, "tester1,123,0\n");
        fprintf(fp_user, "tester2,124,0\n");
    }

    fclose(fp_user);
    fclose(fp_chat);
}

//ip가 어디에 활용되는지 궁금합니다.
/*
유저의 ip, 이름, 밴 여부를 받아서 DB에 작성한다.
input : long ip, char* name, int isban
output : 
return :
*/
void WriteName(long int user_ip, char *user_name, int is_ban)
{
    fprintf(fp_user, "%s,%ld,%d\n", user_name, user_ip, is_ban);
}

//m_id가 어떤 정보인지 모르겠네요. 변수 이름을 자세히 적어주시거나 주석으로 달아주시면 감사하겠습니다.
//+id랑 ip는 다른 개념인가요.
/*
유저의 m_id, 전송id, 수신id, 채팅, 현재시간을 받아서 DB에 작성한다.
input : long m_id, long sender_id, long receiver_id, char* user_text, int cur_time
output : 
return :
*/
void WriteMessage(long int m_id, long int from_id, long int to_id, char *user_text, int cur_time)
{
    fprintf(fp_chat, "%ld,%ld,%ld,%s,%d\n", m_id, from_id, to_id, user_text, cur_time);
}