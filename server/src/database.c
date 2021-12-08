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
#define DB_DELIMITER ','
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1
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

/*
이름을 입력받고 이름의 사용 가능 여부를 클라이언트로 전송하는 함수
input : char* name
output : char* name, char* void, bool ispossible
return : 
*/
void isPossibleName(char *user_name)
{
    int fd;
    int i, j, k;
    short int check_name_exist = 0;

    if ((fd = open(DB_USER, O_RDONLY)) == -1)
    {
        perror("Error : No database file.\n");
        exit(1);
    }

    //search DB
    char one_line_string[128], name_string[32], *parsing_string;
    //첫 줄은 db 정보
    fgets(one_line_string, 128, fd);

    //parsing
    while (NULL != fgets(one_line_string, 128, fd) && !check_name_exist)
    {
        parsing_string = one_line_string;
        for (i = 0; *parsing_string; i++)
        {
            parsing_string = GetNextString(parsing_string, DB_DELIMITER, name_string);
            if (i != 0)
            {
                continue;
            }
            printf("name : %s\n", name_string);
            if (strcmp(name_string, user_name) == 0)
            {
                check_name_exist = 1;
                //break;
            }
        }
    }
    if (check_name_exist)
    {
        printf("Result : name is already in the DB.\n");
    }
    
    close(fd);
}
/*
파일의 시작과 임시 저장할 버퍼를 통해 다음 정보의 시작 위치를 반환하는 함수.
input : char* file_start, char* file_buffer
output : 
return : char* user_data
*/
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=tipsware&logNo=221690858146
char* getNextString(char *db_start, char *db_buffer)
{
    //delimiter가 나올때 까지 buffer에 저장
    while (*db_start && *db_start != DB_DELIMITER)
    {
        *db_buffer++ = *db_start;
    }
    //한 라인이 끝나는 위치라면 줄바꿈 문자 대신 널문자로 대체해준다.
    if (*(db_buffer - 1) == '\n')
    {
        *(db_buffer - 1) = 0;
    }
    else
    {
        *db_buffer = 0;
    }

    if (*db_start == DB_DELIMITER)
    {
        db_start++;
    }

    // 탐색을 완료한 위치의 주소를 반환한다.
    return db_start;
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
    fp_user = fopen(DB_USER, "w+");
    fp_chat = fopen(DB_CHAT, "w+");

    if (fp_user == NULL)
    {
        fprintf(fp_user, "USER_NAME,USER_IP,IS_BAN\n");
    }
    if (fp_chat == NULL)
    {
        fprintf(fp_chat, "ID,FROM,TO,CONTENT,TIME\n");
    }
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