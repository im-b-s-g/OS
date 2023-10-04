//Q3. Write a Program to Implement and visualize the flow of FORK() command

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    if (fork())
    {
        if (!fork())
        {
            fork();
            printf("1\n");
        }
        else
        {
            printf("2\n");
        }
    }

    else
    {
        printf("3\n");
    }
    printf("4\n");
  printf("\n");
    return 0;
}