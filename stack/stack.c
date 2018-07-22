#include<stdio.h>
int top = -1;
void push(int x,int y[])
{
 if(top == 100)
  printf("\nStack is full\n");
 else
  y[++top] = x;
}

void pop()
{
 if(top == -1)  
  printf("\nStack is empty\n");
 else
  top--;
}

void display(int y[])
{
 int i = 0;
 for(i=0;i<=top;i++)
  printf("%d ",y[i]);
}
 
void main()
{
 int A[100],ch,ele;
 char ch1;
 printf("Stack Menu\n");
 printf("\n1. Push element\n2. Pop element\n3. Display\n");
 do
 {
  printf("\nEnter choice ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter element to push ");
          scanf("%d",&ele);
          push(ele,A);
          break;
   case 2:pop(); 
          break;
   case 3:display(A);
          break;
   default:printf("\nInvalid input\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch1);
 }while(ch1 == 'y' || ch1 == 'Y');
}
