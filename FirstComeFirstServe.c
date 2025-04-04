#include <stdio.h>
void main() {
    int p[10],at[10], bt[10], ct[10], wt[10], tat[10], i, j, temp=0, n;
    float awt = 0, atat = 0;
    printf("Enter the number of process you want");
    scanf("%d",&n);
    printf("Enter the processes");
    for(i = 0;i < n; i++) {
        scanf("%d",&p[i]);
    }
    printf("Enter the arrival times");
    for(i = 0;i < n; i++) {
        scanf("%d",&at[i]);
    }
    printf("Enter the burst times");
    for(i = 0;i < n; i++) {
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n;i++) {
        for(j =0; j < n -i -1; j++) {
            if(at[j] > at[j+1]) {
                temp = p[j+1];
                p[j+1] = p[j];
                p[j] = temp;
                temp = at[j+1];
                at[j+1] = at[j];
                at[j] = temp;
                temp = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = temp;
            }
        }
    }
    ct[0] = at[0] + bt[0];
    for( i =1; i< n;i ++) {
        temp = 0;
        if( ct[i-1] , at[i]) {
            temp = at[i] - ct[i-1];
        }
        ct[i] = ct[i-1] +bt[i] = temp;
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\t");
    for(i=0;i<n;i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        atat += tat[i];
        awt += wt[i];
    }
    atat = atat/n;
    for(i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Waverage atat is %f",atat);
    printf("Aerage wt is %f",awt);
    return 0;
}