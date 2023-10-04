/* Q2. Write a C progeam to Impement fork() Command where the parent creates a zombie process which gets executed after the terminatio of a program */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forkexample()
{
	int n;
	printf("Enter range of the array from 0 to 'n'\n");
	scanf("%d", &n);
	int cSum =0, pSum =0;
        if (fork() == 0){
			sleep(5);
        for(int i=0;i<n; i++ )
		{
			if(i%2!=0)
			{
			printf("child's Odd number is %d\n", i);
			cSum+=i;
			}
		}
		printf("****Child Odd Sum is: %d ***** \n", cSum);
		}
    
    else
        {
			
			 
        for(int i=0;i<n; i++)
		{
			if(i%2==0)
			{
			printf("Parent's Even number is %d\n", i);
			pSum+=i;
			}
		}
				printf("***Parent's Even Sum is: %d **** \n", pSum);
		}
}
int main()
{
    forkexample();
    return 0;
}