#include<stdio.h>

int f = -1;
int r = -1;
int N = 10;

void push(int ele,int A[])
{
 if(r == -1)
 {
  A[++r] = ele;
  f = r;
 }
 else if( f == (r+1)%N )
 {
  printf("\nQueue is full\n");
 }
 else
 {
  r = (r+1)%N;
  A[r] = ele;
 }
}

void pop()
{
 if(f == -1)
  printf("\nQueue is empty\n");
 else if(f == r)
  f = r = -1;
 else 
  f = (f+1)%N;
}

void display(int A[])
{
 if(f == -1)
  printf("\nQueue is empty\n");
 else
 {
  int i = f;
  for(;i != r+1;i++)
  {
   printf("%d ",A[i%N]);
  }
 }
} 
  
void main()
{
 int A[10],ch,ele;
 char ch1;
 printf("Queue Menu\n");
 printf("\n1. Push element\n2. Pop element\n3. Display element\n");
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
