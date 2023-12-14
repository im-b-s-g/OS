#include <stdio.h>
#include <stdlib.h>

struct Process {
    int processID;
    int burstTime;
    int tempburstTime;
    int responsetime;
    int arrivalTime;
    int priority;
    int outtime;
    int intime;
};

void insert(struct Process Heap[], struct Process value, int* heapsize, int* currentTime) {
    int start = *heapsize, i;
    Heap[*heapsize] = value;
    if (Heap[*heapsize].intime == -1)
        Heap[*heapsize].intime = *currentTime;
    ++(*heapsize);

    while (start != 0 && Heap[(start - 1) / 2].priority > Heap[start].priority) {
        struct Process temp = Heap[(start - 1) / 2];
        Heap[(start - 1) / 2] = Heap[start];
        Heap[start] = temp;
        start = (start - 1) / 2;
    }
}

void order(struct Process Heap[], int* heapsize, int start) {
    int smallest = start;
    int left = 2 * start + 1;
    int right = 2 * start + 2;
    if (left < *heapsize && Heap[left].priority < Heap[smallest].priority)
        smallest = left;
    if (right < *heapsize && Heap[right].priority < Heap[smallest].priority)
        smallest = right;

    if (smallest != start) {
        struct Process temp = Heap[smallest];
        Heap[smallest] = Heap[start];
        Heap[start] = temp;
        order(Heap, heapsize, smallest);
    }
}

struct Process extractminimum(struct Process Heap[], int* heapsize, int* currentTime) {
    struct Process min = Heap[0];
    if (min.responsetime == -1)
        min.responsetime = *currentTime - min.arrivalTime;
    --(*heapsize);
    if (*heapsize >= 1) {
        Heap[0] = Heap[*heapsize];
        order(Heap, heapsize, 0);
    }
    return min;
}

int compare(const void* a, const void* b) {
    return ((struct Process*)a)->arrivalTime - ((struct Process*)b)->arrivalTime;
}

void scheduling(struct Process Heap[], struct Process array[], int n, int* heapsize, int* currentTime) {
    if (*heapsize == 0)
        return;

    struct Process min = extractminimum(Heap, heapsize, currentTime);
    min.outtime = *currentTime + 1;
    --min.burstTime;
    printf("process id = %d current time = %d\n", min.processID, *currentTime);

    if (min.burstTime > 0) {
        insert(Heap, min, heapsize, currentTime);
        return;
    }

    for (int i = 0; i < n; i++)
        if (array[i].processID == min.processID) {
            array[i] = min;
            break;
        }
}

void priority(struct Process array[], int n) {
    qsort(array, n, sizeof(struct Process), compare);

    int totalwaitingtime = 0, totalbursttime = 0, totalturnaroundtime = 0, i, insertedprocess = 0,
        heapsize = 0, currentTime = array[0].arrivalTime, totalresponsetime = 0;

    struct Process Heap[4 * n];

    for (int i = 0; i < n; i++) {
        totalbursttime += array[i].burstTime;
        array[i].tempburstTime = array[i].burstTime;
    }

    do {
        if (insertedprocess != n) {
            for (i = 0; i < n; i++) {
                if (array[i].arrivalTime == currentTime) {
                    ++insertedprocess;
                    array[i].intime = -1;
                    array[i].responsetime = -1;
                    insert(Heap, array[i], &heapsize, &currentTime);
                }
            }
        }
        scheduling(Heap, array, n, &heapsize, &currentTime);
        ++currentTime;
        if (heapsize == 0 && insertedprocess == n)
            break;
    } while (1);

    for (int i = 0; i < n; i++) {
        totalresponsetime += array[i].responsetime;
        totalwaitingtime += (array[i].outtime - array[i].intime - array[i].tempburstTime);
        totalbursttime += array[i].burstTime;
    }

    printf("Average waiting time = %f\n", ((float)totalwaitingtime / (float)n));
    printf("Average response time = %f\n", ((float)totalresponsetime / (float)n));
    printf("Average turn around time = %f\n", ((float)(totalwaitingtime + totalbursttime) / (float)n));
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process array[n];

    for (int i = 0; i < n; i++) {
        array[i].processID = i + 1;
        printf("Enter arrival time for P%d: ", array[i].processID);
        scanf("%d", &array[i].arrivalTime);
        printf("Enter priority for P%d: ", array[i].processID);
        scanf("%d", &array[i].priority);
        printf("Enter burst time for P%d: ", array[i].processID);
        scanf("%d", &array[i].burstTime);
    }

    priority(array, n);

    return 0;
}
