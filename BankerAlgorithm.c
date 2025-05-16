#include <stdio.h>
int main() {
    int n,m,c=0,completed=0;
    printf("Enter the number of processes and resources\n");
    scanf("%d %d",&m,&n);
    int alloc[m][n],max[m][n],need[m][n],avail[n],done[m],sequence[m];
    for(int i=0;i<m;i++) {
        done[i] = 0;
    }
    printf("Enter the Allocation matrix\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter the Max matrix\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&max[i][j]);

    for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                need[i][j] = max[i][j] - alloc[i][j];

    printf("Enter the available resources\n");
    for(int i=0; i<n;i++)
        scanf("%d",&avail[i]);

    for(int k=0;k<m;k++) {
        for(int i =0; i<m; i++) {
            if(!done[i]) {
                int count = 0;
                for(int j=0; j<n; j++) {
                    if(need[i][j] <= avail[j])
                        count++;
                }
                if(count == n) {
                    for(int j=0; j<n; j++) {
                        avail[j] += alloc[i][j]; 
                    }
                    done[i] = 1;
                    sequence[c++] = i;
                    completed++;
                }
            }
        }
    }
    
    if (completed == m) {
        printf("System in safe state\n");
        printf("Safe Sequence :\n");
        for(int i =0; i<m;i++) {
            printf("P%d",sequence[i]);
            if( i < m - 1) printf(" -> ");
        }
        printf("\n");
    }
    else {
        printf("\nThe system is in an UNSAFE state (Deadlock may occur).\n");
    }
    return 0;
}