//Shortest Job First Scheduling Algorithm with Arrival Time

 #include <stdio.h>
 #include <stdlib.h>

 int P[20],AT[20],BT[20],WT[20],TAT[20],TBT[20],n,i,j;
 float avg_wt,avg_tat;

 void SJFS(){
    int count=0;
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
    for(i=0;i<n;i++){
        TBT[i]=BT[i];
    }
    count = AT[0];
    for(i=0;i<n;i++){
        WT[i]=count;
        count += TBT[i]; 
        if(AT[i+1]>count){
            TAT[i]=count-AT[i];    
        }else if(BT[i+1]<BT[i]){
            TBT[i] -= (AT[i+1]-count);
             
        }

    }
 }

 