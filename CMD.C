void main(int arg ,char *argv[])
{
int t=0,i;
clrscr();
printf("Arg=%d\n",arg-1);
for(i=1;i<arg;i++)
{
t=t+atoi(argv[i]);
}
printf("Sum :%d",t);
getch();
}