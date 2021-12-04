/*
Name : database.c

Prototype Goal:
server initDB() -> make file or stay.
server isPossibleName() -> search DB -> {write data in DB and sendData(success)} or sendData(error)

*/

#include <stdio.h>
#include <fcntl.h>

#define DB_USER "./data/DB_User.csv"
#define DB_CHAT "./data/DB_Chat.csv"
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1
FILE* fp_user; //유저 관련 파일포인터
FILE* fp_chat; //채팅 관련 파일포인터

typedef struct userData
{
    int user_ip;
    char user_name[512];
}user_data;

//extern function test
void sendData(char* user_name, char* user_text, int response_data);

//function declare

/*
이름을 입력받고 이름의 사용 가능 여부를 클라이언트로 전송하는 함수
input : char* name
output : char* name, char* void, bool ispossible
return : 
*/
void isPossibleName(char *user_name)
{
    int fd;
    if ((fd = open(DB_USER, O_RDONLY)) == -1)
    {
        perror("Error : No database file.\n");
        exit(1);
    }
    //test
    if (DEBUG)
    {
        WriteName(123, user_name, 0);
        //sendData(user_name, "", 0);
    }

    close(fd);
}

/*
프로그램을 처음 시작할 때 사용.
csv파일의 첫번째 줄, 유저 데이터 항목을 적는다.
input : 
output : 
return : 
*/
void initDB(){
    fp_user=fopen(DB_USER,"w+");
    fp_chat=fopen(DB_CHAT,"w+");

    fprintf(fp_user,"USER_NAME,USER_IP,IS_BAN\n");
    fprintf(fp_chat,"ID,FROM,TO,CONTENT,TIME\n");
}

//ip가 존재하는 이유가 뭔지 궁금합니다. 다른 컴퓨터에서는 그 이름으로 로그인 못하게 되는 건가요.
/*
유저의 ip, 이름, 밴 여부를 받아서 DB에 작성한다.
input : long ip, char* name, int isban
output : 
return :
*/
void WriteName(long int user_ip, char* user_name,int is_ban) {
    fprintf(fp_user, "%s,%ld,%d\n", user_name, user_ip, is_ban);
}

//m_id가 어떤 정보인지 모르겠네요. 변수 이름을 자세히 적어주시거나 주석으로 달아주세요.
//+id는 뭐고 ip는 뭔가요.
/*
유저의 m_id, 전송id, 수신id, 채팅, 현재시간을 받아서 DB에 작성한다.
input : long m_id, long sender_id, long receiver_id, char* user_text, int cur_time
output : 
return :
*/
void WriteMessage(long int m_id,long int from_id,long int to_id,char* user_text,int cur_time) {
    fprintf(fp_chat, "%ld,%ld,%ld,%s,%d\n", m_id, from_id, to_id, user_text, cur_time);
}