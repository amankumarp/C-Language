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
int c=0;
struct node* createSparse();
void display(struct node *);
void insertToResult(int,int,int);
struct node* addSparse(struct node*,struct node*);
void main()
{
struct node* t,*t1,*r;
clrscr();
t=createSparse();
t1=createSparse();
display(t);
printf("\n");
display(t1);
r=addSparse(t,t1);
display(r);
getch();
}
struct node* createSparse()
{
struct node *newnode,*head=NULL,*last=NULL;
int c,i,j,n,x,r,v;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter total row,column and value :");
scanf("%d%d%d",&r,&c,&v);
newnode->r=r;
newnode->c=c;
newnode->v=v;
newnode->link=NULL;
if(head==NULL)
head=last=newnode;
else
{
last->link=newnode;
last=newnode;
}
n=v;
for(i=1;i<=n;i++)
{
printf("Enter row,column and value:");
scanf("%d%d%d",&r,&c,&v);
newnode=(struct node*)malloc(sizeof(struct node));
newnode->r=r;
newnode->c=c;
newnode->v=v;
newnode->link=NULL;
last->link=newnode;
last=newnode;
}
return(head);
}
void display(struct node *t)
{
while(t!=NULL)
{
printf("%d %d %d\n",t->r,t->c,t->v);
t=t->link;
}
}
struct node* addSparse(struct node *p,struct node *q)
{
struct node *temp;
int r1,c1,v1;
r1=p->r;
c1=p->c;
v1=0;
p=p->link;
q=q->link;
insertToResult(r1,c1,v1);
while(p!=NULL && q!=NULL)
{
if(p->r==q->r&&p->c==q->c)
{
v1=p->v+q->v;
r1=p->r;
c1=p->c;
p=p->link;
q=q->link;
}
else if((p->r<q->r)||(p->r==q->r&&p->c<q->c))
{

 v1=p->v;
 r1=p->r;
 c1=p->c;
 p=p->link;
 }
 else
 {
 v1=q->v;
 r1=q->r;
 c1=q->c;
 q=q->link;
 }
 insertToResult(r1,c1,v1);

}
while(p!=NULL)
{
insertToResult(q->r,q->c,q->v);
q=q->link;
}
headr->v=c;
return(headr);
}


void insertToResult(int r,int c,int v)
{
struct node *re;
c++;
re=(struct node *)malloc(sizeof(struct node));
re->r=r;
re->c=c;
re->v=v;
re->link=NULL;
if(headr==NULL)
{
headr=lastr=re;
}
else
{
lastr->link=re;
lastr=re ;
}
}
