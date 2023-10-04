#include <stdio.h>
#include <unistd.h>

struct
{
    int process_Id;
    int burst_Time;
    int completion_Time;
    int Arrival_Time;
    int turn_Around_Time;
    int waiting_Time;

} typedef Process;


int main()
{

    int number_Of_Processes = 0;

    printf("Enter the number of processes. \n");
    scanf("%d", &number_Of_Processes);

    Process p[number_Of_Processes];

    for (int i = 0; i < number_Of_Processes; i++)
    {
        printf("Enter Process_Id, burst_Time and Arrival_Time of Process %d.\n", i);
        scanf("%d %d %d", &p[i].process_Id, &p[i].burst_Time, &p[i].Arrival_Time);
    }

    // print and Sort the structure according to arrival time

    int value = 0;

    printf("Press 1 to Print the Values\n");
    scanf("%d", &value);

    if (value == 1)
    {
        printf("-----------------------------------------------------------------------------------------\n");
        printf("Process_Id \t burst_Time \t Arrival_Time\n");
        printf("-----------------------------------------------------------------------------------------\n");
        for (int i = 0; i < number_Of_Processes; i++)
        {

            printf("\t%d \t\t %d \t\t %d \n", p[i].process_Id, p[i].burst_Time, p[i].Arrival_Time);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    }

    Process p2;
    int flag=0;

    for (int i = 0; i < number_Of_Processes; i++)
    {
        flag=1;
        for (int j = 0; j < (number_Of_Processes - i); j++)
        {
            if (p[j].Arrival_Time > p[j + 1].Arrival_Time)
            {
                flag=0;
                // p2=p[j]
                p2.Arrival_Time = p[j].Arrival_Time;
                p2.burst_Time = p[j].burst_Time;
                p2.process_Id = p[j].process_Id;
                // p[j] = p[j+1]
                p[j].Arrival_Time = p[j + 1].Arrival_Time;
                p[j].burst_Time = p[j + 1].burst_Time;
                p[j].process_Id = p[j + 1].process_Id;
                // p[j+1] = p2
                p[j + 1].Arrival_Time = p2.Arrival_Time;
                p[j + 1].process_Id = p2.process_Id;
                p[j + 1].burst_Time = p2.burst_Time;
            }
        }
        if(flag)
            break;
    }

    // Print the structure

    printf("Sorting Completed\n\n");
    value = 0;

    printf("Press 1 to Print the Values after Sorting\n");
    scanf("%d", &value);

    if (value == 1)
    {

        printf("-----------------------------------------------------------------------------------------\n");
        printf("Process_Id \t burst_Time \t Arrival_Time\n");
        printf("-----------------------------------------------------------------------------------------\n");
        for (int i = 0; i < number_Of_Processes; i++)
        {
            printf("\t%d \t\t %d \t\t %d \n", p[i].process_Id, p[i].burst_Time, p[i].Arrival_Time);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    }

    // calculate Completion time
    int sum = 0;
    for (int i = 0; i < number_Of_Processes; i++)
    {
        sum += p[i].burst_Time;
        p[i].completion_Time = sum;
    }

    printf("Completion_time Calculation Complete.\n");
    value = 0;

    printf("Press 1 to Add Completion_time to the Table\n");
    scanf("%d", &value);

    if (value == 1)
    {

        printf("-----------------------------------------------------------------------------------------\n");
        printf("Process_Id \t burst_Time \t Arrival_Time\t\t Completion_Time\n");
        printf("-----------------------------------------------------------------------------------------\n");

        for (int i = 0; i < number_Of_Processes; i++)
        {
            printf("\t%d \t\t %d \t\t %d \t\t\t%d \n", p[i].process_Id, p[i].burst_Time, p[i].Arrival_Time, p[i].completion_Time);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    }

    // calculate turn_around_time

    for (int i = 0; i < number_Of_Processes; i++)
    {
        p[i].turn_Around_Time = p[i].completion_Time - p[i].Arrival_Time;
    }

    // calculate waiting Time

    for (int i = 0; i < number_Of_Processes; i++)
    {
        p[i].waiting_Time = p[i].turn_Around_Time - p[i].burst_Time;
    }
    printf(" Calculating waiting Time and Turn around time Complete. \n");

    value = 0;
    printf("Press 1 to add waiting_Time and turn_Around_Time to the table \n");
    scanf("%d", &value);

    if (value == 1)
    {

        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("Process_Id \t burst_Time \t Arrival_Time\t\t Turn_Around_Time \t\t Completion_Time \t\t Waiting_Time\n");
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < number_Of_Processes; i++)
        {
            printf("\t%d \t\t %d \t\t %d \t\t\t%d \t\t\t\t %d \t\t\t\t %d \n", p[i].process_Id, p[i].burst_Time, p[i].Arrival_Time, p[i].turn_Around_Time, p[i].completion_Time, p[i].waiting_Time);
        }
        printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
    }

    return 0;
}