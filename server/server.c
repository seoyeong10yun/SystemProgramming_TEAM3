#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1

//function extern test
void isPossibleName(char *userName);

//function declare
void sendData(char* userName, char* text, int responseData);

int main(){
    if (DEBUG){
        printf("It runs in Debug mod.\n");
    }
    
    char testName[50] = "fhiller";
    isPossibleName(testName);

    return 0;
}

//implementations of functions
void sendData(char* userName, char* text, int responseData){
    if (DEBUG)
    {
        printf("userName : %s, text : %s, responseData : %d\n", userName, text, responseData);
    }
    
}