#include<stdio.h>
#include<math.h>
int top = -1;

void push(char s[],char x)
{
 if(top == 19)
  printf("\nStack is full\n");
 else
 {
  s[++top] = x;
 }
}

int pop(char s[])
{
 if(top == -1)
  printf("\nStack is empty\n");
 else
  return s[top--];
}

void main()
{
 char in[30],s[30];
 int i;
 printf("\nEnter an expression ");
 scanf("%[^\n]%*c",in);
 for(i=0;in[i] != '\0';i++)
 {
  if(in[i] >= 48 && in[i] <= 57)
   push(s,in[i]);
  else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/'|| in[i] == '^')
  {
   int y = pop(s) - 48;
   int x = pop(s) - 48;
   int z;
   switch(in[i])
   {
    case '+':z = (x+y)+48;
             push(s,z);
             break;
    case '-':z = (x-y)+48;
             push(s,z);
             break;
    case '*':z = (x*y)+48;
             push(s,z);
             break;
    case '/':z = (x/y)+48;
             push(s,z);
             break;
    case '^':z = pow(x,y)+48;
             push(s,z);
   }
  }
 }
 printf("\nThe answer is %d\n",pop(s)-48);
}
    
