#include<stdio.h>
#include<stdlib.h>
void ls()
{
    int size,a[100],x,flag=0,loc;
    printf("\nENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&size);
    printf("\nENTER THE ARRAY ELEMENTS:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nENTER THE ELEMENT TO BE SEARCHED: ");
    scanf("%d",&x);
    for(int i=0;i<size;i++)
    {
        if(x==a[i])
        {
            flag=1;
            loc=i;
            break;
        }
    }
    if(flag==1)
    {
        printf("\nELEMENET FOUND AT THE POSITION %d USING LINEAR SEARCH",loc+1);
    }
    else
    {
        printf("\nELEMENT NOT FOUND!!");
    }
}
void bs()
{
    int size,a[100],flag=0,x;
    printf("\nENTER THE SIZE OF THE ARRAY:");
    scanf("%d",&size);
    printf("\nENTER THE ARRAY ELEMENTS:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;        
            }
        }
    }
    printf("\nSORTED ARRAY:");
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }

    printf("\nENTER THE ELEMENT TO BE SEARCHED: ");
    scanf("%d",&x);
    
    int beg=0,end=size-1,mid;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if(x<a[mid])
        {
            end=mid;
        }
        else if(x>a[mid])
        {
            beg=mid+1;
        }
        else
        {
            printf("\nELEMENT FOUND AT THE POSITION %d USING BINARY SEARCH!",mid+1);
            flag=1;
            break;
        }
        
        
    }
    if(flag==0)
    {
        printf("ELEMENT NOT FOUND IN THE ARRAY..!!");
    }
}
void main()
{
    int c;
    do
    {
         printf("\n1.LINEAR SEARCH\n2.BINARY SEARCH\n3.EXIT\nENTER YOUR CHOICE:");
         scanf("%d",&c);
        switch(c)
        {
            case 1:ls();break;
            case 2:bs();break;
            case 3:exit(0);break;
            default:printf("\nINVALID CHOICE..!!");
        }
    } while (c!=3); 
}