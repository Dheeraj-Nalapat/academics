//Indexed File Allocation

#include<stdio.h>
#include<stdlib.h>

struct sector{
    int used;
    int next;
}s[100];

int directory[100][2];
int sNo,nFree;
int dSpace;

void indexed(){
    int nFiles,nBlocks,curBlock=0,start;
    int indexBlock[10][100],directory[10];
    printf("\nEnter the number of files:");
    scanf("%d",&nFiles);
    for(int i=0;i<nFiles;i++){
        if(nFree == 0){
            printf("\nAll sectors are full\n");
            break;
        }
        printf("\nFile%d:",i);
        do{
            printf("\nEnter the indexed block:");
            scanf("%d",&directory[i]);
            if(s[directory[i]].used == 1){
                printf("\nThis sector is already used\n");
            }
        }while(s[directory[i]].used == 1);
        s[directory[i]].used = 1;
        nFree--;
        do{
            printf("\nEnter Starting position:");
            scanf("%d",&start);
            if(s[start].used == 1){
                printf("\nThis sector is already used\n");
            }
        }while(s[start].used == 1);
        int current = start;
        printf("\nEnter the number of blocks in the file:");
        scanf("%d",&nBlocks);
        indexBlock[i][0] = nBlocks;
        if(nFree<nBlocks){
            printf("\nNot enough space\n");
            break;
        }else{
            current = start;
            for(int j=0;j<nBlocks;j++){
                if(s[current].used){
                    while (s[current].used)
                    {
                        current = (current+1)%sNo;
                    }
                }
                s[current].used = 1;
                indexBlock[i][j+1] = current;
            }
            nFree -= nBlocks;
            printf("\nThe File was allocated");
        }    
    }
    printf("\n INDEX BLOCK:\n");
    for(int i=0;i<nFiles;i++){
        printf("\nFile%d index block at sector%d\n:",i,directory[i]);
        for(int j=1;j<indexBlock[i][0]+1;j++){
            printf("%d ",indexBlock[i][j]);
        }
        printf("\n");
    }
}

void main(){
    printf("\nEnter the number of sectors:");
    scanf("%d",&sNo);
    for(int i=0;i<sNo;i++){
        s[i].used = 0;
    }
    nFree = sNo;
    indexed();
}
