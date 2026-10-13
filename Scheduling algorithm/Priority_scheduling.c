#include <stdio.h>

struct Process {
    int id;
    int priority;
    int burst_time;
};

void priorityScheduling(struct Process processes[], int n) {
    // Sort processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                // Swap the processes
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Display the order of execution
    printf("Order of execution: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].id);
    }
    printf("\n");
}

int main() {
    int n;

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input details of each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority for Process P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    // Perform priority scheduling
    priorityScheduling(processes, n);

    return 0;
}
