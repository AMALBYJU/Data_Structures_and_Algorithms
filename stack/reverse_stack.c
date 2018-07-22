#include<stdio.h>
int top = -1;
int A[20];
void insertatbottom();
void push(int x,int y[])
{
 if(top == 19)
  printf("\nStack is full\n");
 else
  y[++top] = x;
}

int pop()
{
 if(top == -1)  
  printf("\nStack is empty\n");
 else
  return A[top--];
}

void display(int y[])
{
 int i = 0;
 for(i=0;i<=top;i++)
  printf("%d ",y[i]);
}

void reverse()
{
 if(top == -1)
  return;
 else
 {
   int data = pop();
   reverse();
   push(data,A);
   insertatbottom();
   return;
 }
}

void insertatbottom()
{
 int k = top;
 int b = A[top];
 while(k != -1)
 {
  A[k+1] = A[k];
  k--;
 }
 A[0] = b;
} 


void main()
{
 int ch,ele;
 char ch1;
 printf("Stack Menu\n");
 printf("\n1. Push element\n2. Pop element\n3. Display\n4. Reverse\n");
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
   case 4:reverse();
          break;
   default:printf("\nInvalid input\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch1);
 }while(ch1 == 'y' || ch1 == 'Y');
}
