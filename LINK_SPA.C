#include<stdio.h>
#include<conio.h>
struct node
{
int r;
int c;
int v;
struct node *link;
};
struct node *headr=NULL,*lastr=NULL;
struct node* create();
void display(struct node*);
struct node* add(struct node*,struct node *);
void insertToResult(int,int,int);

void main()
{
struct node *t1,*t2,*t3;
clrscr();
t1=create();
t2=create();
printf("First mat:\n");
display(t1);
printf("Second mat:\n");
display(t2);
t3=add(t1,t2);
printf("Sum:\n");
display(t3);
getch();
}
struct node* create()
{
struct node *newnode,*head=NULL,*last=NULL;
int r1,c1,v1,n,i;
printf("Enter the total row,column and Value:");
scanf("%d%d%d",&r1,&c1,&v1);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->r=r1;
newnode->c=c1;
newnode->v=v1;
newnode->link=NULL;
head=last=newnode;
n=v1;
for(i=1;i<=n;i++)
{
printf("Enter row ,column and Value:");
scanf("%d%d%d",&r1,&c1,&v1);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->r=r1;
newnode->c=c1;
newnode->v=v1;
newnode->link=NULL;
last->link=newnode;
last=newnode;
}
return(head);
}
void display(struct node*temp )
{
if(temp==NULL)
{
printf("Matrix is empty");
getch();
return;
}
while(temp!=NULL)
{
printf("%d %d %d\n",temp->r,temp->c,temp->v);
temp=temp->link;
}
}
struct node* add(struct node *p,struct node* q)
{
int r1,c1,v1,n,i;
r1=p->r;
c1=p->c;
v1=0;
insertToResult(r1,c1,v1);
p=p->link;
q=q->link;
while(p!=NULL && q!=NULL)
{
 if((p->r==q->r)&&(p->c==q->c))
 {
 r1=p->r;
 c1=q->c;
 v1=q->v+p->v;
 p=p->link;
 q=q->link;
 }
 else if((p->r<q->r)||(p->r==q->r&&p->c<q->c))
 {
 r1=p->r;
 c1=p->c;
 v1=p->v;
 p=p->link;
 }
 else
 {
 r1=q->r;
 c1=q->c;
 v1=q->v;
 q=q->link;
 }
 insertToResult(r1,c1,v1);
 }
 while(p!=NULL)
 {
  insertToResult(p->r,p->c,p->v);
  p=p->link;
  }
  while(q!=NULL)
  {
  insertToResult(q->r,q->c,q->v);
  q=q->link;
  }
  return(headr);
}
void insertToResult(int r,int c,int v)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->r=r;
newnode->c=c;
newnode->v=v;
newnode->link=NULL;
if(headr==NULL)
headr=lastr=newnode;
else
{
lastr->link=newnode;
lastr=newnode;
}
}
