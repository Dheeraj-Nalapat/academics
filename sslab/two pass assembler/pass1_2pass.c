// Pass one of a 2 pass assembler

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input,*symtab,*output,*optab;
    char label[20],opcode[20],operand[20],code[20],mnemonic[20],symbol[20];
    int locctr,start,length;
    input = fopen("input.txt","r");
    symtab = fopen("symtab.txt","w");
    output = fopen("intermediate.txt","w");
    optab = fopen("optab.txt","r");
    fscanf(input,"%s%s%X",label,opcode,&start);
    if(strcmp(opcode,"START")==0){
        locctr = start;
        fprintf(output,"%X\t%s\t%s\t%X\n",locctr,label,opcode,locctr);
    }
    else{
        locctr = 0;
    }
    while(strcmp(opcode,"END")!=0){
        fprintf(output,"%X\t",locctr);
        if(strcmp(label,"-")!=0){
            fprintf(symtab,"%s\t%X\n",label,locctr);
        }
        fseek(optab,SEEK_SET,0);
        while(fscanf(optab,"%s\t%s",code,mnemonic)!=EOF){
            if(strcmp(opcode,code)==0){
                locctr += 3;
                break;
            }
        }
        if(strcmp(opcode,"WORD")==0){
            locctr += 3;
        }
        else if(strcmp(opcode,"RESW")==0){
            locctr += (3*atoi(operand));
        }
        else if(strcmp(opcode,"RESB")==0){
            locctr += atoi(operand);
        }
        else if(strcmp(opcode,"BYTE")==0){
            ++locctr;
        }
        fprintf(output,"%s\t%s\t%s\n",label,opcode,operand);
        fscanf(input,"%s\t%s\t%s",label,opcode,operand);    
    }    
    fprintf(output,"%X\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    length = locctr - start;
    printf("The length of the program is %X",length);
    fclose(input);
    fclose(symtab);
    fclose(output);
    fclose(optab);
    return 0;
}