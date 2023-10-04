#include<stdio.h>
#include<unistd.h>

struct p
{   
    int processId;
    int burst_Time;
    int waiting_Time;
    int turnAround_Time;
} typedef process;

int main()
{
    float totalTurnaroundTime=0.0, totalWaitingTime=0.0;
    int numberOfProcesses,timeQuantum=0;
    int done=0;
    process p[numberOfProcesses];
    printf("Enter the number of Processes. \n");
    scanf("%d", &numberOfProcesses);
    
    int remainingBurstTime[numberOfProcesses];

    printf("Enter the CPU time Quantum. \n");
    scanf("%d", &timeQuantum);

    printf("---------------------------------------------------------\n");
    printf("Enter Burst time for Each process.\n");
    printf("---------------------------------------------------------\n");

    for(int i=0; i<numberOfProcesses; i++)
    {
        p[i].processId=i+1;
        printf("\nEnter Burst time of process %d \n",i+1);
        scanf("%d", &p[i].burst_Time);
    }

    for(int i=0; i<numberOfProcesses;i++)
        remainingBurstTime[i]=p[i].burst_Time;

    int time=0;

    while(1)
    {
        done = 1;

        for(int i=0; i<numberOfProcesses;i++)
        {
            if(remainingBurstTime[i]>0)
            {
                done=0;
                if(remainingBurstTime[i]>timeQuantum)
                {
                    time += timeQuantum;
                    remainingBurstTime[i]-=timeQuantum;
                }
                else
                {
                    time+=remainingBurstTime[i];
                    p[i].waiting_Time = time - p[i].burst_Time;
                    remainingBurstTime[i]=0;
                }
            }
        }
        if(done==1)
        {
            break;
        }
    }


    for(int i =0; i<numberOfProcesses; i++)
    {
        p[i].turnAround_Time =  p[i].burst_Time + p[i].waiting_Time; 
    }

    printf("------------------------------------------------------------------------------------\n");
    printf("ProcessId \t\t BurstTime \t\t WaitingTime \t\t ProcessTAT \n");
    printf("------------------------------------------------------------------------------------\n");
    
    for(int i =0; i<numberOfProcesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t %d \t\t\t %d \n", p[i].processId,p[i].burst_Time,p[i].waiting_Time,p[i].turnAround_Time);
    }
    
    printf("------------------------------------------------------------------------------------\n");


}
