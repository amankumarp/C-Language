//linked list 1
#include<stdio.h>
#include<conio.h>
struct node
{
int data;
struct node *link;
};
void fast_Add(int);
void last_Add(int);
void add_sp(int,int);
int last_del();
int fast_del();
int del_sp(int);
void display();
struct node *head=NULL,*last=NULL;
void main()
{
int n,ch,pos;
while(1)
{
clrscr();
printf("1.InsertBegin\n2.SpecificInsert\n3.LastInsert\n4.First Delete\n5.Delete Specific\n6.Last Delete\n7.Display\n8.Exit\nEnter your Choice...");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter a number:");
scanf("%d",&n);
fast_Add(n);
break;
case 2:
printf("Enter a number:");
scanf("%d",&n);
printf("Enter position:");
scanf("%d",&pos);
add_sp(pos,n);
break;
case 3:
printf("Enter a number:");
scanf("%d",&n);
last_Add(n);
break;
case 4:
n=fast_del();
if(n!=-1)
printf("%d is delete",n);
getch();
break;
case 6:
n=last_del();
if(n!=-1)
printf("%d is delete",n);
getch();
break;
case 5:
printf("Enter  position:");
scanf("%d",&pos);
n=del_sp(pos);
if(n!=-1)
printf("%d is delete",n);
getch();
break;
case 7:
display();
getch();
break;
case 8:
exit(0);
}
}
}
void fast_Add(int n)
{
struct node * p;
p=(struct node *)malloc(sizeof(struct node ));
p->data=n;
p->link=head;
head=p;
}

void last_Add(int n)
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
void add_sp(int pos ,int n)
{

}
void display()
{
struct node *t;
if(head==NULL)
{
printf("Link list is Empty");
return;
}
t=head;
while(t!=NULL)
{
printf("%d\n",t->data);
t=t->link;
}
}
int last_del()
{
struct node *p,*t;
int i=0,j,n;
if(head==NULL)
{
printf("Link list is Empty");
return(-1);
}
else
t=head;
while(t->link!=NULL)
{
t=t->link;
i++;
}
p=t;
t=head;
for(j=0;j<i-1;j++)
{
t=t->link;
}
n=p->data;
t->link=NULL;
free(p);
return(n);
}
int fast_del()
{
int n;
struct node *t;
if(head==NULL)
{
printf("list is Empty");
return(-1);
}
else
t=head;
n=t->data;
head=t->link;
free(t);
return n;
}
int del_sp(int pos)
{
}
