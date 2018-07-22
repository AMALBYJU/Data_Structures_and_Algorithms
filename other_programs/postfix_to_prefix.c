#include<string.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 20

char str[MAX], stack[MAX];
int top = -1;

char pop()
{
      return stack[top--];
}

void push(char ch)
{
      stack[++top] = ch;
}

void postfix_to_prefix(char expression[])
{
      int count, length;
      length = strlen(expression);
      printf("\nPrefix Expression:\t");
      for(count = length - 1; count >= 0; count--)
      {
            printf("%c", expression[count]);
      }
}

int main()
{
      char postfix_expression[35];
      printf("\nEnter Postfix Expression:\t");
      scanf("%s", postfix_expression);
      postfix_to_prefix(postfix_expression);
      printf("\n");
      return 0;
}
