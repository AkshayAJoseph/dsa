#include<stdio.h>
struct process
{
    int id,pt,at,bt,ct,tat,wt,stat;
};
void main()
{
    struct process p[20];
    int n,i;
    float tottat=0,totwt=0,avgtat=0,avgwt=0;
    int comp=0,current_time=0;
    printf("Enter Number of Processes : ");
    scanf("%d",&n);
    printf("Enter Process Details : \n");
    for(i=0;i<=n-1;i++)
    {
        printf("Enter id | pt | at | bt :\t");
        scanf("%d%d%d%d",&p[i].id,&p[i].pt,&p[i].at,&p[i].bt);
        p[i].stat=0;
    }
    while(comp!=n)
    {
        int index=-1,min=32765;
        for(i=0;i<=n-1;i++)
        {
            if((p[i].at<=current_time) && (p[i].stat==0))
            {
                if(p[i].pt<min)
                {
                    min=p[i].pt;
                    index=i;
                }
            }
        }
        if(index==-1)
        {
            current_time++;
        }
        else
        {
            current_time=current_time+p[index].bt;
            p[index].ct=current_time;
            comp++;
            p[index].stat=1;
        }
    }
    for(i=0;i<=n-1;i++)
    {

        p[i].tat=p[i].ct-p[i].at;
        tottat=tottat+p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        totwt=totwt+p[i].wt;
    }
    avgtat=tottat/n;
    avgwt=totwt/n;
    printf("ID\tPT\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d \t%d \t%d \t%d \t%d \t%d \t%d\n",p[i].id,p[i].pt,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Turn Around Time : %f\n",avgtat);
    printf("Average Waiting Time     : %f\n",avgwt);
}
