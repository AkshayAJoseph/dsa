#include <stdio.h>

int main() {
    int n,t=0,comp=0;
    float ttat=0,twt=0,atat,awt;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n];
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

    for(int i=0;i<n;i++) {
        if(t<AT[i])
            t = AT[i];
        else
            t += BT[i];
        CT[i] = t;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        ttat += TAT[i];
        twt += WT[i];
    }
    atat = ttat/n;
    awt = twt/n;

    printf("P\t AT\t BT\t CT\t TAT\t WT\n");
    for(int i=0; i<n;i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t\n",P[i],AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
    printf("The average Turn Around Time is %.2f\n",atat);
    printf("The average Waiting Time is %.2f\n",awt);
}