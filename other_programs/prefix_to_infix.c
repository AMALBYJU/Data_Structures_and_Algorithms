#include<stdio.h>
#include<string.h>
int top = -1;
char x[30],y[30];
void push(char s[30][30],char d[])
{
 if(top == 29)
  printf("\nStack is full\n");
 else
 {
   strcpy(s[++top],d);
 }
}

void pop(char s[][30])
{
 if(top == -1)
  printf("\nStack is empty\n");
 else
 {
  strcpy(x,s[top--]);
  strcpy(y,s[top--]);
 }
}

void main()
{
 int i;
 char s[30][30],in[30],t[2],z[30];
 printf("\nEnter an expression ");
 scanf("%[^\n]%*c",in);
 for(i=strlen(in)-1;i>=0;i--)
 {
  t[0] = in[i];
  t[1] = '\0';
  if(in[i] >=97 && in[i] <=122)
  {
   push(s,t);
  }
  else if(in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/')
  {
   pop(s);
   strcpy(z,"(");
   strcat(z,x);
   strcat(z,t);
   strcat(z,y);
   strcat(z,")");
   push(s,z);
  }
 }
 printf("\nThe infix expression is %s\n",s[0]);
}
