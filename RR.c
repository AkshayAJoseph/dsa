#include <stdio.h>

int rear = -1, front = -1, rq[20];

void enqueue(int item) {
    if (rear == 19) {
        return;
    }
    if (rear == -1) {
        front = 0;
    }
    rq[++rear] = item;
}

int dequeue() {
    if(rear == -1 || front > rear) {
        return -1;
    }
    int value = rq[front++];
    return value;
}

int isEmpty() {
    if(rear == -1 || front > rear) {
        return 1;
    }
    return 0;
}


int isIn (int n) {
    for (int i = front; i <= rear; i++) {
        if (n == rq[i])
            return 1;
    }
    return 0;
}

int main() {
    int n, tq, comp = 0, t = 0;
    float ttat = 0, twt = 0, atat, awt;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int P[n], AT[n], BT[n], CT[n], TAT[n], WT[n], BTT[n], done[n];

    // Input
    printf("Enter the process IDs: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }

    printf("Enter the Arrival Times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &AT[i]);
    }

    printf("Enter the Burst Times: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &BT[i]);
        BTT[i] = BT[i]; // Save original burst time
        done[i] = 0;     // Mark all as not done
    }

    printf("Enter the Time Quantum: ");
    scanf("%d", &tq);

    while(comp < n) {
         for(int i = 0; i < n; i++) {
            if(AT[i] <= t && done[i] == 0) {
                if(!isIn(i)) 
                    enqueue(i);
            }
        }

        if(isEmpty()) {
            t++;
        }
        else {
            int idx = dequeue();
            if (BTT[idx] > tq) {
                t += tq;
                BTT[idx] -= tq;
            }
            else {
                t += BTT[idx];
                BTT[idx] = 0;
                done[idx] = 1;
                comp++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BTT[i];
        ttat += TAT[i];
        twt += WT[i];
    }

    atat = ttat / n;
    awt = twt / n;

    // Output
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i], AT[i], BT[i], CT[i], TAT[i], WT[i]);
    }

    printf("\nAverage Turnaround Time: %.2f\n", atat);
    printf("Average Waiting Time   : %.2f\n", awt);

    return 0;
}
