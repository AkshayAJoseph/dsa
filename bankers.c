#include <stdio.h>

int main() {
    int alloc[20][20], max[20][20], need[20][20], available[20];
    int m, n, sequence[20], status[20], completed = 0;
    int c = 0;

    printf("Enter the number of processes and resources: ");
    scanf("%d %d", &m, &n);

    printf("Enter the Allocation Matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the Max Matrix (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &max[i][j]);

    // Calculate need matrix
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    printf("Enter the Available Resources (%d values): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &available[i]);

    // Initialize status array
    for (int i = 0; i < m; i++) {
        status[i] = 0; // Not completed
    }

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            if (status[i] == 0) {
                int count = 0;
                for (int j = 0; j < n; j++) {
                    if (need[i][j] <= available[j])
                        count++;
                }   
                if (count == n) {
                    // Process can be completed
                    for (int j = 0; j < n; j++) {
                        available[j] += alloc[i][j];
                    }
                    status[i] = 1;
                    sequence[c++] = i;
                    completed++;
                }
            }
        }
    }

    if (completed == m) {
        printf("\nThe system is in a SAFE state.\n");
        printf("Safe Sequence: ");
        for (int i = 0; i < m; i++) {
            printf("P%d", sequence[i]);
            if (i < m - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nThe system is in an UNSAFE state (Deadlock may occur).\n");
    }

    return 0;
}