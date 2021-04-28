/*
Forras: 
Dr. Vadasz Denes: Operacios rendszerek
*/


#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#define SECOND 1

void do_nothing();
void do_int();

int main(int argc, char const *argv[])
{
    int i;
    unsigned sec = 1 ;

    signal(SIGINT, do_int);

    for(i=1; i<8; i++){
        alarm(sec);
        signal(SIGALRM, do_nothing);
        printf("%d varok de meddig?\n", i);
        pause();
    }

    return 0;
}

void do_nothing(){;}
void do_int(){
    printf("int jott\n");
    signal(SIGINT, SIG_IGN);
}
