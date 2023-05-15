// write a c program to simulate the following cpu scheduling algorithms 
// 1. FCFS
// 2. SJF
// 3. round robin
// 4. Priority

#include <stdio.h>

void fcfs(){
    int n , bt[20], wt[20], tat[20] , i , j ;
    float avwt =0 , avtat = 0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("Enter the burst time of n processes:\n");
    wt[0]=0;
    for(i=0;i<n;i++){
        scanf("%d",&bt[i]);
        wt[i]=0;
        tat[i]=0;
    }
    tat[0] = bt[0];
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        avtat += tat[i];
        avwt += wt[i];
    }
    avtat /= n;
    avwt /= n;
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time:%f\n",avwt);
    printf("Average Turn Around Time:%f\n",avtat);    
}

void sjfs(){
    int n , bt[20],wt[20],tat[20],p[20],i,j,temp;
    float avgtat=0,avgwt=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    p[0] = 1;
    printf("Enter the burst time for each process\n");
    for(int i=0;i<n;i++){
        printf("BT[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i]= i+1;
        wt[i]=0;
        tat[i]=0;
    }
    for(i =0;i<n;i++){
        for(j= i;j<n;j++){
            if(bt[i]>bt[j]){
                temp = bt[i];
                bt[i] = bt[j] ;
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for(int i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
        avgtat += tat[i];
        avgwt += wt[i];
    }
    avgtat /= n;
    avgwt /= n;
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time:%f\n",avgwt);
    printf("Average Turn Around Time:%f\n",avgtat);   
}

void round_robin(){
    int n,bt[20],wt[20],tat[20],at[20],i,j;
    float avgtat=0,avgwt=0;
    
}

void main(){
    fcfs();
    sjfs();
}