#include <stdio.h>
#include <stdlib.h>

void CSCAN(int arr[], int size, int head, int disk_size, const char *direction) {
    int seek_count = 0;
    int distance, cur_track;
    int *left = NULL, *right = NULL;
    int left_count = 0, right_count = 0;
    int i, j;

    left = (int*)malloc(size * sizeof(int));
    right = (int*)malloc(size * sizeof(int));

    if (!left || !right) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // appending end values which have to be visited before reversing the direction
    left[left_count++] = 0;
    right[right_count++] = disk_size - 1;

    // tracks on the left of the head will be serviced when once the head comes back to the beginning (left end).
    for (i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_count++] = arr[i];
        if (arr[i] > head)
            right[right_count++] = arr[i];
    }

    // sorting left and right vectors
    for (i = 0; i < left_count - 1; i++) {
        for (j = 0; j < left_count - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < right_count - 1; i++) {
        for (j = 0; j < right_count - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // first service the requests on the right side of the head.
    for (i = 0; i < right_count; i++) {
        cur_track = right[i];
        // appending current track to seek sequence
        printf("%d, ", cur_track);
        // calculate absolute distance
        distance = abs(cur_track - head);
        // increase the total count
        seek_count += distance;
        // accessed track is now new head
        head = cur_track;
    }

    // once reached the right end jump to the beginning.
    head = 0;

    // adding seek count for head returning from (disk_size - 1) to 0
    seek_count += (disk_size - 1);

    // Now service the requests again which are left.
    for (i = 0; i < left_count; i++) {
        cur_track = left[i];
        // appending current track to seek sequence
        printf("%d, ", cur_track);
        // calculate absolute distance
        distance = abs(cur_track - head);
        // increase the total count
        seek_count += distance;
        // accessed track is now the new head
        head = cur_track;
    }

    printf("\nTotal number of seek operations = %d\n", seek_count);
}

int main() {
    int size = 8;
    int arr[] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
    int disk_size;

    printf("Request sequence = {");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("}\n");

    printf("Initial head position = %d\n", head);
    printf("Direction = right (We are moving from left to right)\n");

    printf("Enter the size of the disk: ");
    scanf("%d", &disk_size);

    printf("Output:\n");
    printf("Initial position of head: %d\n", head);
    printf("Seek Sequence: ");
    
    CSCAN(arr, size, head, disk_size, "right");

    return 0;
}
