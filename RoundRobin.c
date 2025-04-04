#include <stdio.h>
#include <limits.h>

struct process {
    int id, at, bt, ct, tat, wt, remaining_bt, stat;
};

int main() {
    struct process p[20];
    int n, i, quantum, comp = 0, current_time = 0;
    float tottat = 0, totwt = 0, avgtat = 0, avgwt = 0;

    printf("Enter Number of Processes : ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    printf("Enter Process Details : \n");
    for (i = 0; i < n; i++) {
        printf("Enter id | at | bt :\t");
        scanf("%d%d%d", &p[i].id, &p[i].at, &p[i].bt);
        p[i].remaining_bt = p[i].bt;
        p[i].stat = 0; // Process is not completed initially
    }

    while (comp != n) {
        int all_completed = 1;
       
        for (i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].stat == 0) {
                all_completed = 0; // At least one process is not completed
                if (p[i].remaining_bt > quantum) {
                    current_time += quantum;
                    p[i].remaining_bt -= quantum;
                } else {
                    current_time += p[i].remaining_bt;
                    p[i].ct = current_time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    tottat += p[i].tat;
                    totwt += p[i].wt;
                    p[i].stat = 1; // Mark process as completed
                    comp++;
                    p[i].remaining_bt = 0;
                }
            }
        }

        if (all_completed) {
            current_time++;
        }
    }

    avgtat = tottat / n;
    avgwt = totwt / n;

    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d \t%d \t%d \t%d \t%d \t%d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average Turn Around Time : %f\n", avgtat);
    printf("Average Waiting Time     : %f\n", avgwt);

    return 0;
}
