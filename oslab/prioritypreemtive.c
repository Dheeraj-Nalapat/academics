// priority scheduling algorithm using preemtive scheduling
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int n,p[10],bt[10],at[10],pri[10],wt[10],tat[10],tbt[10],t=0,sum=0;

void sort(){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pri[i]>pri[j]){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=pri[i];
                pri[i]=pri[j];
                pri[j]=temp;
            }
            // else if(at[i]==at[j]){
            //     if(pri[i]>pri[j]){
            //         temp = p[i];
            //         p[i] = p[j];
            //         p[j] = temp;
            //         temp=bt[i];
            //         bt[i]=bt[j];
            //         bt[j]=temp;
            //         temp=at[i];
            //         at[i]=at[j];
            //         at[j]=temp;
            //         temp=pri[i];
            //         pri[i]=pri[j];
            //         pri[j]=temp;
            //     }
            // }
        }
    }
}

void priority(){
   sort();
   for(int i=0;i<n;i++){
       tbt[i]=bt[i];
       sum+=bt[i];
   }
   for(int i=0;i<n;i++){
       wt[i]=0;
       tat[i]=0;
   }
   int total = at[n-1]+sum;
   for(int t=0;t<total;t++){
         for(int i=0;i<n;i++){
              if(at[i]<=t && bt[i]>0){
                printf("%d ",p[i]);
                bt[i]--;
                wt[i]++;
                break;
              }
         }
   }
}

void main(){
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the arrival time ,burst time and priority of each process: \n");
    for(int i=0;i<n;i++){
        printf("Process %d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pri[i]);
        p[i]=i+1;
    }
    priority();
}