#include<stdio.h>
#include<stdlib.h>
// Converts infix to postfix using expression tree
char stack[50];
int top = -1;
char pfx[50];
char ifx[50];

void push(char x)
{
 if(top == 49)
  printf("\nStack is full\n");
 else
  stack[++top] = x;
}

int pop()
{
 if(top == -1)
  printf("\nStack is empty\n");
 else
  return stack[top--];
}

int prec(char x)
{
 if(x == '+'|| x == '-')
  return 1;
 else if(x == '*' || x == '/')
  return 2;
 else if(x == '^')
  return 3;
 else
 {
  printf("\nInvalid character found\nTerminating program\n");
  exit(0);
 }
}
  
void main()
{
 int i,k = 0;
 printf("\nEnter infix expression ");
 scanf("%[^\n]%*c",ifx);
 for(i = 0;ifx[i] != '\0';i++)
 {
  if(ifx[i] == '(')
  {
   push(ifx[i]);
  }
  else if((ifx[i] >= 97 && ifx[i] <= 122) || (ifx[i] >= 65 && ifx[i] <=90))
  {
   pfx[k++] = ifx[i];
  }
  else if(ifx[i] == ')')
  {
   char r = pop();
   while(r != '(')
   {
    pfx[k++] = r;
    r = pop();
   }
  }
  else
  {
   while(stack[top] != '(' && top != -1)
   {
    if(prec(stack[top]) >= prec(ifx[i]))
    {
     pfx[k++] = pop();
    }
    else
     break;
   }
   push(ifx[i]);
  }
 }
 pfx[k++] = pop();
 pfx[k] = '\0';
 printf("\nThe postfix expression is %s",pfx);
}
  
   
