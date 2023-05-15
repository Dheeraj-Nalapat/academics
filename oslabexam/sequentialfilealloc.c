// Sequential File Allocation

#include<stdio.h>
#include<stdlib.h>

struct sector{
    int used;
    int next;
}s[100];

int directory[100][2];
int sNo,nFree;
int dSpace;

void sequential(){
    int nFiles,curBlock=0,nBlocks;
    printf("\nEnter the no of files:");
    scanf("%d",&nFiles);
    for(int i=0;i<nFiles;i++){
        if(nFree == 0){
            printf("\nAll sectors are full\n");
            break;
        }
        printf("\nFile%d:",i);
        printf("\nStarting position: %d",curBlock);
        printf("\nEnter the number of blocks in the file:");
        scanf("%d",&nBlocks);
        if(nFree<nBlocks){
            printf("\nNot enough space\n");
            break;
        }else{
            for(int j=curBlock;j<curBlock+nBlocks;j++){
                s[j].used = 1;
                if(j>curBlock){
                    printf("->");
                }
                printf("%d",j);
            }
                printf("\nThe File was allocated");
                curBlock += nBlocks;
                nFree -= nBlocks;
        }
    }
}

void main(){
    printf("\nEnter the number of sectors:");
    scanf("%d",&sNo);
    for(int i=0;i<sNo;i++){
        s[i].used = 0;
    }
    nFree = sNo;
    sequential();
}