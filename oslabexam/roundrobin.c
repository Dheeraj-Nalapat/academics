// Round Robin Scheduling Algorithm

#include <stdio.h>
#include <stdlib.h>

int P[20],AT[20],BT[20],WT[20],TAT[20],n,i,j,time_slice,tempBT[20],k;
float avg_wt,avg_tat;

void RR(){
    k=0;
    avg_tat=0;
    avg_wt=0;
    int time=0;
    int count = n;
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
                temp = tempBT[i];
                tempBT[i] = tempBT[j];
                tempBT[j] = temp;
            }
        }
    }
    for(i=0;i<n;i++){
        WT[i]=0;
        TAT[i]=0;
    }
    printf("Gant Chart: ");
    if(AT[0]>0){
        printf("IDOL->");
    }
    while (count!=0){
        if(tempBT[k]==0){
            k = (k+1)%n;
            continue;
        }
        if(tempBT[k]>time_slice){
            tempBT[k] -= time_slice;
            time += time_slice;
            printf("P[%d]->",k+1);

        }else{
            time += tempBT[k];
            TAT[k] = time;
            WT[k] = TAT[k] - BT[k];
            tempBT[k] = 0;
            avg_tat += TAT[k];
            avg_wt += WT[k];
            count--;
            printf("P[%d]->",k+1);
        }
        k = (k+1)%n;
        if(AT[k]>time ){
            k = (k-1)%n;
            if(tempBT[k]==0){
                printf("IDOL->");
            }
        }
    }
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf(" %d\t %d\t %d\t %d\t %d \n",P[i],AT[i],BT[i],WT[i],TAT[i]);
    }
    avg_tat /= n;
    avg_wt /= n;
    printf("Average Turn Around Time: %f\n",avg_tat);
    printf("Average Waiting Time: %f\n",avg_wt);
}

void main(){
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the burst time and arival time of the processes:");
    for(i=0;i<n;i++){
        printf("\nProcess[%d]:",i+1);
        scanf("%d   %d",&BT[i],&AT[i]);
        P[i]=i+1;
        tempBT[i]=BT[i];
        WT[i]=0;
    }
    printf("Enter the time slice:");
    scanf("%d",&time_slice);
    RR();
}