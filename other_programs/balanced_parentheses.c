#include<stdio.h>
#include<stdlib.h>
int top = -1;
void push(char ele,char S[])
{
 if(top == 29)
 {
   printf("\nStack is full\n");
   exit(0);
 }
 else
 {
  S[++top] = ele;
 }
}

void pop(char c,char S[])
{
 if(top == -1)
 {
  printf("\nExpression does not have balanced parentheses\n");
  exit(0);
 }
 else
 {
  if(c == S[top])
  --top;
 }
}

void main()
{
 int i;
 char S[30],C[30];
 printf("Enter an expression ");
 scanf("%[^\n]%*c",C);
 for(i=0;C[i]!='\0';i++)
 {
  if(C[i] == '(' || C[i] == '{' || C[i] == '[')
   push(C[i],S);
  if(C[i] == ')' || C[i] == '}' || C[i] == ']')
  {
    pop(C[i],S);
  }
 }
 if(top > -1)
  printf("\nExpression does not have balanced parentheses\n");
 else
  printf("\nExpression has balanced parentheses\n");
 S[++top] = '\0';
 printf("\n%s\n",S);
}
