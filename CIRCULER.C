#include<stdio.h>
#include<conio.h>
void insertQ(int n);
int readQ();
void display();
int q[10],rear=-1,front=-1,max=10;
void main()
{
int n,ch;
while(1)
{
clrscr();
printf("\t\t\t\tCircullar Queue\n1.Insert\n2.Read\n3.Display\n4.Exit\nYour choice...");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter a number:");
scanf("%d",&n);
insertQ(n);
break;
case 2:
n=readQ();
if(n==-1)
getch();
else
printf("%d is deleted",n);
getch();
break;
case 3:
display();
getch();
break;
case 4:
exit(0);
}
}
}
void insertQ(int n)
{
if(front==(rear+1)%max)
{
printf("Queue overflow\npress a key \n");
getch();
return;
}
if(front==-1)
front=rear=0;
else
rear=(rear+1)%max;
q[rear]=n;

}
int readQ()
{
int n;
if(front==-1)
{
printf("Queue is empty");
return(-1);
}
n=q[front];
if(front ==rear)
front=rear=-1;
else
front=(front+1)%max;
return(n);
}
void display()
{
int i;
for(i=front;i<=rear;i++)
printf("%d ",q[i]);

}