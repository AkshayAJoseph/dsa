#include <stdio.h>

int main() {
    int n, time_quantum, t = 0, completed = 0;
    float total_tat = 0, total_wt = 0, avg_tat, avg_wt;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    int P[n], AT[n], BT[n], RT[n], CT[n], TAT[n], WT[n], done[n];
    
    // Initialize arrays
    for(int i = 0; i < n; i++) {
        done[i] = 0;  // Process not completed
    }
    
    printf("Enter the process IDs:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }
    
    printf("Enter the Arrival Times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &AT[i]);
    }
    
    printf("Enter the Burst Times:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
        RT[i] = BT[i];  // Initialize remaining time with burst time
    }
    
    printf("Enter the Time Quantum: ");
    scanf("%d", &time_quantum);
    
    // Sort processes by arrival time
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(AT[j] < AT[i]) {
                // Swap all related arrays
                int temp = P[i];
                P[i] = P[j];
                P[j] = temp;
                
                temp = AT[i];
                AT[i] = AT[j];
                AT[j] = temp;
                
                temp = BT[i];
                BT[i] = BT[j];
                BT[j] = temp;
                
                temp = RT[i];
                RT[i] = RT[j];
                RT[j] = temp;
            }
        }
    }
    
    // Set initial time to first process arrival time if not 0
    if (n > 0 && AT[0] > 0) {
        t = AT[0];
    }
    
    // Round Robin Scheduling
    while(completed < n) {
        int all_waiting = 1;  // Flag to check if all processes are waiting
        
        for(int i = 0; i < n; i++) {
            if(RT[i] > 0 && AT[i] <= t) {  // Process has remaining time and has arrived
                all_waiting = 0;  // At least one process is not waiting
                
                if(RT[i] <= time_quantum) {  // Process can complete in this time quantum
                    t += RT[i];
                    CT[i] = t;
                    RT[i] = 0;
                    done[i] = 1;
                    completed++;
                    
                    // Calculate TAT and WT
                    TAT[i] = CT[i] - AT[i];
                    WT[i] = TAT[i] - BT[i];
                    
                    // Update totals
                    total_tat += TAT[i];
                    total_wt += WT[i];
                } else {  // Process needs more time
                    t += time_quantum;
                    RT[i] -= time_quantum;
                }
                
                // After executing a process for the time quantum, 
                // check if new processes have arrived
                // This is an important step for correct Round Robin implementation
                // to ensure all arrived processes get a fair chance
            }
        }
        
        // If all processes are waiting, jump to the next arrival time
        if(all_waiting) {
            int next_arrival = -1;
            for(int i = 0; i < n; i++) {
                if(!done[i] && (next_arrival == -1 || AT[i] < next_arrival)) {
                    next_arrival = AT[i];
                }
            }
            
            if(next_arrival != -1) {
                t = next_arrival;
            } else {
                // Safety check: should never happen if input is valid
                break;
            }
        }
    }
    
    // Calculate averages
    avg_tat = total_tat / n;
    avg_wt = total_wt / n;
    
    // Display results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }
    printf("-------------------------------------\n");
    printf("The average Turn Around Time is %.2f\n", avg_tat);
    printf("The average Waiting Time is %.2f\n", avg_wt);
    
    return 0;
}