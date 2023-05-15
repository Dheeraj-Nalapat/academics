// Indxed file allocation

#include<stdio.h>
#include<stdlib.h>

int directory[100][2];
int sNo,nFree;
int dSpace;

struct sector{
    int used;
    int next;
}s[100];

void linked(){
    int nFiles,nBlocks,start;
    printf("\nEnter the number of files:");
    scanf("%d",&nFiles);
    for(int i=0;i<nFiles;i++){
        if(nFree == 0){
            printf("\nAll sectors are full\n");
            break;
        }
        printf("\nFile%d:",i);
        do{
            printf("\nEnter the starting position:");
            scanf("%d",&start);
            if(s[start].used == 1){
                printf("\nThis sector is already used\n");
            }
        }while (s[start].used == 1);
        int current = start;        
        printf("\nEnter the number of blocks in the file:");
        scanf("%d",&nBlocks);
        if(nFree<nBlocks){
            printf("\nNot enough space\n");
            break;
        }else{
            for(int j=0;j<nBlocks;j++){
                if(s[current].used){
                    while (s[current].used)
                    {
                        current = (current+1)%sNo;
                    }
                }    
                    s[current].used = 1;
                    if(current!=start)printf("->");
                    printf("%d",current);
            }    
            nFree -= nBlocks;
            printf("\nThe File was allocated");
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
    linked();
}