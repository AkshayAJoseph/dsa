#include <stdio.h>

// Number of processes and resources
int n, m;
int allocation[10][10], max[10][10], need[10][10], available[10];

// Function to calculate Need matrix
void calculateNeed() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

// Function to check if a request can be granted
int isSafe() {
    int work[m], finish[n], safeSequence[n];
    for (int i = 0; i < m; i++) {
        work[i] = available[i];  // Initialize Work = Available
    }
    for (int i = 0; i < n; i++) {
        finish[i] = 0; // Initialize all processes as unfinished
    }

    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {  // If process i is unfinished
                int flag = 1;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) { 
                        flag = 0;  // Cannot execute process i
                        break;
                    }
                }
                if (flag) {
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];  // Free resources
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("\nSystem is in an **Unsafe** state! Deadlock possible.\n");
            return 0;
        }
    }

    // Safe sequence exists
    printf("\nSystem is in a **Safe** state.\nSafe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");
    return 1;
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Max matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter Available resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &available[i]);

    calculateNeed(); // Compute the Need matrix
    isSafe(); // Check if the system is in a safe state

    return 0;
}
