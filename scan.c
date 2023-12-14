#include <stdio.h>
#include <stdlib.h>

// Function to perform SCAN Disk Scheduling
void SCAN(int arr[], int head, int size, char direction) {
    int seek_count = 0;
    int distance, cur_track;
    int left[size], right[size];
    int left_size = 0, right_size = 0;
    int seek_sequence[size + 1];

    // Appending end values which have to be visited before reversing the direction
    left[left_size++] = 0;
    right[right_size++] = 199;

    // Dividing the requests into two arrays based on direction
    for (int i = 0; i < size; i++) {
        if (arr[i] < head)
            left[left_size++] = arr[i];
        if (arr[i] > head)
            right[right_size++] = arr[i];
    }

    // Sorting the left and right arrays
    for (int i = 0; i < left_size - 1; i++) {
        for (int j = 0; j < left_size - i - 1; j++) {
            if (left[j] < left[j + 1]) {
                int temp = left[j];
                left[j] = left[j + 1];
                left[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < right_size - 1; i++) {
        for (int j = 0; j < right_size - i - 1; j++) {
            if (right[j] > right[j + 1]) {
                int temp = right[j];
                right[j] = right[j + 1];
                right[j + 1] = temp;
            }
        }
    }

    // Run the while loop two times, one by one scanning right and left of the head
    int run = 2;
    int sequence_index = 0; // Index to track the seek sequence
    while (run--) {
        if (direction == 'l') {
            for (int i = left_size - 1; i >= 0; i--) {
                cur_track = left[i];
                seek_sequence[sequence_index++] = cur_track;

                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = 'r';
        } else if (direction == 'r') {
            for (int i = 0; i < right_size; i++) {
                cur_track = right[i];
                seek_sequence[sequence_index++] = cur_track;

                distance = abs(cur_track - head);
                seek_count += distance;
                head = cur_track;
            }
            direction = 'l';
        }
    }

    // Display the seek sequence
    printf("\nSeek Sequence is: ");
    for (int i = 0; i < sequence_index; i++) {
        printf("%d ", seek_sequence[i]);
    }

    // Display the total number of seek operations
    printf("\nTotal number of seek operations = %d\n", seek_count);
}

int main() {
    int size, head;

    // Get the size of the request array
    printf("Enter the size of the request array: ");
    scanf("%d", &size);

    // Dynamic allocation of memory for the request array
    int *arr = (int *)malloc(size * sizeof(int));

    // Get the request array
    printf("Enter the request array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Get the initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Get the direction (l for left, r for right)
    char direction;
    printf("Enter the direction (l for left, r for right): ");
    scanf(" %c", &direction);

    // Apply SCAN Disk Scheduling algorithm
    SCAN(arr, head, size, direction);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}
