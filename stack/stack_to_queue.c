#include<stdio.h>

int top1 = -1;
int top2 = -1;
void push(int s1[],int s2[],int s,int ele)
{
 if(s == 1)
 {
  if(top1 == 9)
   printf("\nQueue is full\n");
  else
  {
   s1[++top1] = ele;
  }
 }
 else if(s == 2)
 {
  if(top2 == 9)
   printf("\nQueue is full\n");
  else
  {
   s2[++top2] = ele;
  }
 }
}

int pop(int s1[],int s2[],int s)
{
 if(s==1)
 {
  if(top1 == -1)
   printf("\nQueue is empty\n");
  else
  {
   return s1[top1--];
  }
 }
 if(s==2)
 {
  if(top2 == -1)
   printf("\nQueue is empty\n");
  else
  {
   return s2[top2--];
  }
 }
}

void enqueue(int s1[],int s2[],int ele)
{
 if(top2 != -1)
  push(s1,s2,2,ele)
 else
  push(s1,s2,1,ele);
}

void dequeue(int s1[],int s2[])
{
  while(top1 != 0)
  {
   int x = pop(s1,s2,1);
   push(s1,s2,2,x);
  }
  pop(s1,s2,1);
  while(top2 != -1)
  {
   int x = pop(s1,s2,2);
   push(s1,s2,1,x);
  }
}
  
