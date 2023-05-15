


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x,prio;
}a[100];
int front,rear,size;
void push(int x, int prio)
{
    int i,loc;
    if(front==0&&rear==size-1)
        printf("QUEUE OVERFLOW");
    else if(front==-1)
    {
        front=0;
        rear=0;
        a[rear].x=x;
        a[rear].prio=prio;
    }    
    else
    {
        if(rear==size-1)
        {
            for(i=front;i<rear;i++)
               { a[i-1]=a[i];}
            front--;
            rear--;
        }
        for(i=rear;i>=front;i--)
        {
            if(a[i].prio>prio)
            {
                break;
            }
        }
        loc=i+1;
        for(i=rear;i>=loc;i--)
        {
            a[i+1]=a[i];
        }
        a[loc].x=x;
        a[loc].prio=prio;
        rear++;
    }
}
void pop()
{
    if(front==-1)
    {
        printf("QUEUE UNDERFLOW");
    }
    else if(front==rear)
    {
        printf("THE DELETED ELEMENT IS %d",a[front].x);
        front=-1;
        rear=-1;
    }
    else 
    {
        printf("THE DELETED ELEMENT IS %d",a[front].x);
        front++;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("QUEUE UNDERFLOW");
    }
    else
    {
        printf("ELEMENTS IN THE QUEUE:");
        for(i=front;i<=rear;i++)
        {
           printf("%d ",a[i].x); 
        }
        printf("\nPRIORITY IN THE QUEUE:");
        for(i=front;i<=rear;i++)
        {
           printf("%d ",a[i].prio); 
        }
    }
}
void main()
{
    int c,x,prio;
    front=-1;
    rear=-1;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&size);
    do
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nENTER YOUR CHOICE:");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("ENTER YOUR ITEM AND PRIORITY:");
            scanf("%d %d",&x,&prio);
            push(x,prio);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:exit(0);
            break;
            default:printf("INVALID CHOICE..!!");
        }
    } while (c!=4);
    
}