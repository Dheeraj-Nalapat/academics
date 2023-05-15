// fcfs scheduling algorithm with arrival time

#include <stdio.h>
#include <stdlib.h>

int P[20],AT[20],BT[20],WT[20],TAT[20],n,i,j;
float avg_wt,avg_tat;

void FCFS(){
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(AT[i]>AT[j]){
                int temp=P[i];
                P[i]=P[j];
                P[j]=temp;
                temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;
                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
            }
        }
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            WT[i]+=BT[j];
        }
    }
    for(i=0;i<n;i++){
        TAT[i]=WT[i]+BT[i];
        avg_wt+=WT[i];
        avg_tat+=TAT[i];
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("Process\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",P[i],AT[i],BT[i],WT[i],TAT[i]);
    }
    printf("Average Waiting Time: %f\n",avg_wt);
    printf("Average Turnaround Time: %f\n",avg_tat);
    printf("Gant Chart:\n");
    for(i=0;i<n-1;i++){
        printf("P[%d]->",P[i]);
    }
    printf("P[%d]",P[n-1]);
}

void main(){
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the burst time and arival time of the processes:");
    for(i=0;i<n;i++){
        printf("\nProcess[%d]:",i+1);
        scanf("%d   %d",&BT[i],&AT[i]);
        P[i]=i+1;
        WT[i]=0;
    }
    FCFS();
}