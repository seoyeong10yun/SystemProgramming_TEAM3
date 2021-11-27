#include <stdio.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define DEBUG 1 //when debugging, set value 1

/*
Name : database.c
function : read database or write database

*/

int main(){
    if (DEBUG){
        printf("It runs in Debug mod.\n");
    }
    
    int fd;
    if ((fd = open("database", O_RDONLY)) == -1)
    {
        perror("Error : No database file.\n");
        exit(1);
    }
    close(fd);

    return 0;
}