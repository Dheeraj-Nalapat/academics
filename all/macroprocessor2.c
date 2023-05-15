// pass 2 of macropreprocessor

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
FILE *f1,*f2,*f3,*f4,*f5;
char mne[20],opnd[20],la[20],name[20],mne1[20],opnd1[20],arg[20];
int i,cnt=0;
f1=fopen("minp2.txt","r");
f2=fopen("ntab2.txt","r");
f3=fopen("dtab2.txt","r");
f4=fopen("argtab2.txt","w+");
f5=fopen("op2.txt","w");
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"END")!=0)
{
if(strcmp(mne,"MACRO")==0)
{
fscanf(f1,"%s%s%s",la,mne,opnd);
while(strcmp(mne,"MEND")!=0)
{
fscanf(f1,"%s%s%s",la,mne,opnd);
}
}
else
{
fscanf(f2,"%s",name);
if(strcmp(mne,name)==0)
{
cnt=0;
fscanf(f3,"%s%s",mne1,opnd1);
printf("%s\t%s\t%s",la,mne,opnd);
fprintf(f5,"%s\t%s\t%s",la,mne,opnd);
while(strcmp(mne1,"MEND")!=0)
{
if(opnd1[0]=='&')
{
strcpy(arg,opnd);
for(i=0;i<strlen(arg);i++)
if(arg[i]==',')
{
cnt++;
arg[i]='\0';
}
if(cnt==0)
{
if(strcmp(opnd1,"&LT")==0)
fprintf(f5,"(L,%s)",arg);
else if(strcmp(opnd1,"&GT")==0)
fprintf(f5,"(G,%s)",arg);
else
fprintf(f5,"(,%s)",arg);
}
else
{
if(strcmp(opnd1,"&LT")==0)
fprintf(f5,"(L,%s)",strtok(arg,","));
else if(strcmp(opnd1,"&GT")==0)
fprintf(f5,"(G,%s)",strtok(arg,","));
else
fprintf(f5,"(,%s)",strtok(arg,","));
}
}
else
fprintf(f5,"%s\t%s",mne1,opnd1);
fscanf(f3,"%s%s",mne1,opnd1);
}
}
else
fprintf(f5,"%s\t%s\t%s\n",la,mne,opnd);
}
fscanf(f1,"%s%s%s",la,mne,opnd);
}
fprintf(f5,"%s\t%s\t%s\n",la,mne,opnd);
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
fclose(f5);
printf("PASS 2 is successful");
getch();
}

