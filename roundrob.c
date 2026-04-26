#include<stdio.h>
int main()
{
int n,i;
int at[20],bt[20],rt[20];
int ct[20], wt[20],tat[20];
int time=0,completed=0;
int tq=2;
int found;
printf("Enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter Arrival Time for P%d:",i);
scanf("%d", &at[i]);
printf("Enter Burst Time for P%d:",i);
scanf("%d",&bt[i]);

rt[i]=bt[i];
}
while(completed<n)
{
found=0;
for(i=0;i<n;i++)
{
if(at[i]<=time&&rt[i]>0)
{
found=1;
if(rt[i]>tq)
{
time+=tq;
rt[i]-=tq;

}
else
{
time+=rt[i];
ct[i]=time;
rt[i]=0;
tat[i]=ct[i]-at[i];
wt[i]=tat[i]-bt[i];
completed++;

}
}
}
if(found==0)
{
time++;
}
}
printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
float total_wt=0, total_tat=0;
for(i=0;i<n;i++)
{
total_wt+=wt[i];
total_tat+=tat[i];
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i,at[i],bt[i],ct[i],wt[i],tat[i]);
}
printf("\nAverage Waiting Time = %.2f", total_wt /n);
printf("\nAverage Turnaround Time = %.2f",total_tat/n);

return 0;
}
