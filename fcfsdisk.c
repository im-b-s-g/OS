#include <stdio.h>
#include <stdlib.h>

#define SIZE 8


void FCFS(int arr[], int size, int head)
{
	int seek_count = 0;
	int distance, cur_track;
	
	for (int i = 0; i < size; i++)
	{
		cur_track = arr[i];
		// calculate absolute distance
		distance = abs(cur_track - head);
		// increase the total count
		seek_count += distance;
		// accessed track is now the new head
		head = cur_track;
	}

	printf("Total number of seek operations = %d\n", seek_count);
	// Seek sequence would be the same
	// as the request array sequence
	printf("Seek Sequence is\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}


int main()
{
	int size, head;
	printf("Enter the size of the request array: ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter the request array elements:\n");
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the initial head position: ");
	scanf("%d", &head);
	FCFS(arr, size, head);
	return 0;
}
