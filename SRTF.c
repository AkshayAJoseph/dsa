#include <stdio.h>

int main() {
    int n,t=0,comp=0;
    float ttat=0,twt=0,atat,awt;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n],done[n],BTT[n];
    for(int i=0; i<n;i++) {
        done[i] = 0;
    }
    printf("Enter the processes\n");
    for(int i=0; i<n;i++) {
        scanf("%d",&P[i]);
    }
    printf("Enter the Arrival Times\n");
    for(int i=0; i<n;i++) {
        scanf("%d",&AT[i]);
    }
    printf("Enter the Burst time\n");
    for(int i=0; i<n;i++) {
        scanf("%d",&BT[i]);
    }
    for(int i=0;i<n;i++) {
        int min = i;
        for(int j = i; j<n; j++){
            if(AT[j] < AT[min])
                min = j;
        }
        int temp = P[i];
        P[i] = P[min];
        P[min] = temp;
        temp = AT[i];
        AT[i] = AT[min];
        AT[min] = temp;
        temp = BT[i];
        BT[i] = BT[min];
        BT[min] = temp;
    }
    for(int i=0; i<n;i++) {
        BTT[i] = BT[i];
    }
    while(comp < n) {
        int min = -1;
        for(int i=0; i<n;i++) {
            if(AT[i] <= t && !done[i])
                if(min == -1)
                    min = i;
                else if(BT[min] > BT[i])
                    min = i;
                }
        if(min == -1) {
            t++;
            continue;
        }
        BT[min]--;
        t++;
        if(BT[min] == 0) {
        CT[min] = t;
        done[min] = 1;
        comp++;
}
    }
    for(int i=0;i<n;i++) {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BTT[i];
        ttat += TAT[i];
        twt += WT[i];
    }
    atat = ttat/n;
    awt = twt/n;
    
    printf("P\t AT\t BT\t CT\t TAT\t WT\n");
    for(int i=0; i<n;i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",P[i],AT[i],BTT[i],CT[i],TAT[i],WT[i]);
    }
    printf("The average Turn Around Time is %.2f\n",atat);
    printf("The average Waiting Time is %.2f\n",awt);
}