#include<stdio.h>

struct node
{
int data;
struct node *link;
};
struct node *head=NULL;
void append(int n);
void display();
void main()
{
int n,ch;
while(1)
{
clrscr();
printf("1.Append\n");
printf("2.Dispaly\n");
printf("3.Exit\n");
printf("Your choice...");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter a number:");
scanf("%d",&n);
append(n);
break;
case 2:
display();
break;
case 3:
exit(0);
}

}


}
void append(int n)
{
struct node *p,*t;
p->data=n;
p->link=NULL;
if(head==NULL)
head=p;
else
{
t=head;
while(t->link!=NULL)
{
t=t->link;
}
t->link=p;
}
}
void display()
{
struct node *t;
if(head==NULL)
{
printf("Linked list is Empty");
getch();
return;
}
t=head;
while(t!=NULL)
{
printf("%d\n",t->data);
t=t->link;
}
getch();

}