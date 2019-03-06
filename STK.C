
#include<stdio.h>
#include<conio.h>
int stk[10],top=-1,max=10;
void push(int x)
{
if(top==max-1)
{
printf("stack overflow");
return;
}
stk[top]=x;
top++;
}
int pop()
{
int x;
if(top==-1)
{
printf("stack Empty");
return -1;
}
x=stk[top];
top--;
return x;
}
void main()
{
int ch,x;
clrscr();
printf("\t\t\tSTACK OPERATION\n\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.exit\n");
printf("Enter your choice:");
scanf("%d",&ch);
switch(ch){
case 1:
clrscr();
    printf("Enter a number:");
    scanf("%d",&x);
    push(x);
    main();
case 2:
clrscr();
   x= pop();
   printf("Pop return :",x);
   getch();
   main();
case 3:
    exit(0);
default:
 printf("Wrong Input");


}
 getch();
}
