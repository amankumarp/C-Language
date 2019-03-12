#include<stdio.h>
#include<conio.h>
struct node
{
int c;
int e;
struct node *link;
};
struct node *headr=NULL,*lastr=NULL;
struct node* createPoly();
void display(struct node*);
void insertToResult(int,int);
int evalPoly(struct node*);
struct node* add(struct node*,struct node*);
void main()
{
struct node *p1,*p2,*p3;
int res;
clrscr();
p1=createPoly();
//p2=createPoly();
display(p1);
//printf("\n");
//display(p2);
//printf("\n");
//p3=add(p1,p2);
//display(p3);
res=evalPoly(p1);
printf("Sum:%d",res);
getch();

}
struct node* createPoly()
{
struct node *p,*head=NULL,*last=NULL;
int c1,e1,n,i,j;
printf("Enter the number of term:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the cofficient and exponent of %d term:",i);
scanf("%d%d",&c1,&e1);
p=(struct node*)malloc(sizeof(struct node));
p->c=c1;
p->e=e1;
p->link=NULL;
if(head==NULL)
head=last=p;
else
{
last->link=p;
last=p;
}

}
return(head);
}
void display(struct node *t)
{
if(t==NULL)
{
printf("first create poly ");
getch();
return;
}
while(t!=NULL)
{
printf("%dX%d+",t->c,t->e);
t=t->link;
}
printf("\b ");
}

struct node * add(struct node *p,struct node *q)
{
int c1,e1;
while(p!=NULL && q!=NULL)
{
if(p->e==q->e)
{
c1=p->c+q->c;
e1=p->e;
p=p->link;
q=q->link;
}
else if(p->e>q->e)
{
c1=p->c;
e1=p->e;
p=p->link;
}
else
{
c1=q->c;
e1=q->e;
q=q->link;
}
insertToResult(c1,e1);

}
while(p!=NULL)
{
insertToResult(p->c,p->e);
p=p->link;
}
while(q!=NULL)
{
insertToResult(q->c,q->e);
q=q->link;
}
return(headr);
}

void insertToResult(int c1,int e1)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->c=c1;
temp->e=e1;
temp->link=NULL;
if(headr==NULL)
headr=lastr=temp;
else
{
lastr->link=temp;
lastr=temp;
}
}
int evalPoly(struct node* temp)
{
int sum=0,pw=1,i,x;
printf("Enter value of x:");
scanf("%d",&x);
while(temp!=NULL)
{
pw=1;
for(i=1;i<=temp->e;i++)
{
pw=pw*x;
}
sum=sum+(pw*temp->c);
temp=temp->link;
}
return(sum);
}