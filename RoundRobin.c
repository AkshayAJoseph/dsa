#include<stdio.h>
struct process{
int id,at,bt,ct,tat,wt,status,qstatus,rt; //qstatus- status of queue and rt- remaining time.
};

int Q[100],front=-1,rear=-1;

void enqueue(int item)
   {
     if(rear==-1)
      {
       rear++;
       front++;
       Q[rear]=item;
      }
     else
      {
       rear++;
       Q[rear]=item;
       }
      }
     
int dequeue()
{
 int item=Q[front];
 front++;
return item;  
}

int main()
{
 struct process p[20];
 int n,i,j,t,current_time=0,completed=0;
 float avg_tat=0,avg_wt=0,tot_tat=0,tot_wt=0;
 printf("Enter the number of processes: \n");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
  {
   printf("Enter the id,at,bt: \n");
   scanf("%d %d %d",&p[i].id,&p[i].at,&p[i].bt);
   p[i].status=0;
   p[i].qstatus=0;
   p[i].rt=p[i].bt;
   }
   
  printf("Enter the time quantum: \n");
  scanf("%d",&t);
   enqueue(0);
   p[0].qstatus=1;
   current_time=p[0].at;
   while(completed!=n)
   {
     int i= dequeue();
     if (p[i].rt>t)
      {
       current_time+=t;
       p[i].rt-= t;
       }
     else
     {
       current_time+=p[i].rt;
       p[i].ct=current_time;
       p[i].status=1;
       completed++;
       p[i].tat=p[i].ct-p[i].at;
       p[i].wt=p[i].tat-p[i].bt-(p[i].bt-p[i].rt);
       p[i].rt=0;
     }
     
     for(j=i+1;j<n;j++)
     {
       if(p[j].at<=current_time&&p[j].status==0&&p[j].qstatus==0)
       {
        enqueue(j);
        p[j].qstatus=1;
        }
      }
      if(p[i].rt!=0)
        {
         enqueue(i);
        }
    }
    for(i=0;i<n;i++)
    {
      tot_tat+=p[i].tat;
      tot_wt+=p[i].wt;
}
avg_tat=tot_tat/n;
          avg_wt=tot_wt/n;

printf("Process Details:\n");

printf("id \t at \t bt \t ct \t tat \t wt \n");


for(i=0;i<n;i++)
{
printf("%d \t %d \t %d \t %d \t %d \t %d \n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

}
printf("Average Turnaround time= %0.2f\n",avg_tat);

printf("Average Waiting time= %0.2f",avg_wt);

}
