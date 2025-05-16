#include <stdio.h>

int main() {
    int n,t=0,comp=0;
    float ttat=0,twt=0,atat,awt;
    printf("Enter the number of processes\n");
    scanf("%d",&n);
    int P[n],AT[n],BT[n],CT[n],TAT[n],WT[n],done[n],PT[n];
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
    printf("Enter the Priority\n");
    for(int i=0; i<n;i++) {
        scanf("%d",&PT[i]);
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
        temp = PT[i];
        PT[i] = PT[min];
        PT[min] = temp;
    }
    while(comp < n) {
        int min=-1;
        for(int j=0; j<n; j++)
            if(!done[j] && AT[j] <= t)
                if(min==-1)
                    min = j;
                else if(PT[min] > PT[j])
                    min =j;

        if(min == -1){
            t++;
            continue;
        }

        t += BT[min];
        CT[min] = t;
        TAT[min] = CT[min] - AT[min];
        WT[min] = TAT[min] - BT[min];
        ttat += TAT[min];
        twt += WT[min];
        done[min] = 1;
        comp++;
    }
    atat = ttat/n;
    awt = twt/n;
    
    printf("P\t AT\t BT\t Priority\t CT\t TAT\t WT\n");
    for(int i=0; i<n;i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\t\n",P[i],AT[i],BT[i],PT[i],CT[i],TAT[i],WT[i]);
    }
    printf("The average Turn Around Time is %.2f\n",atat);
    printf("The average Waiting Time is %.2f\n",awt);
}