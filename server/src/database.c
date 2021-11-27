#pragma once

#include <stdio.h>
#include <fcntl.h>

#define database "../data/database.csv"
#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1

/*
Name : database.c
function : read database or write database

*/

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

// No main function in this file.
// int main(){
//     if (DEBUG)
//     {
//         printf("It runs in Debug mod.\n");
//     }

//     return 0;
// }