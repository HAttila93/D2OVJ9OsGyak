/*
Forras:
Dr. Vadasz Denes: Operacios rendszerek
*/

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void do_nothing();

int main(int argc, char const *argv[])
{
    signal(SIGALRM, do_nothing);
    printf("Varok de meddig?\n");
    pause();
    printf("Vegre, itt az alarm\n");
    return 0;
}

void do_nothing(){;}