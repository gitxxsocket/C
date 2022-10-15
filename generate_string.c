#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int password(int password_length)
{
    char list[] = "1234567890qwertyuiopasdfghjklzxcvbnm!@#$%^&*()-+=QWERTYUIOPASDFGHJKLZXCVBNM[]{}<>?";
    printf("\t");
    for (int i = 0; i < 100; i++)
    {
        printf("*");
    }
    printf("\n");
    printf("\t");
    time_t t;

    srand((unsigned)time(&t));
    for (int i = 0; i < password_length; i++)
    {
        printf("%c", list[rand() % (sizeof list - 1)]);
    }
    printf("\n");
    printf("\t");
    printf("\n");
}
int main(int argc,char **argv)
{
    unsigned int password_length ;
    printf("\t*********************************\n");
    printf("\n\tEnter length of the password = ");
    scanf("%d", &password_length);
    printf("\n");
    password(password_length);
    return 0;
}


