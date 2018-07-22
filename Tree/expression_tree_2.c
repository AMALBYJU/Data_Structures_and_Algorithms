#include<stdio.h>
#include<stdlib.h>

struct node 
{
 char c;
 struct node *left;
 struct node *right;
};

void trav_inorder(struct node *traverse)
{
 if(traverse->left != NULL)
  trav_inorder(traverse->left);
 printf("%c",traverse->c);
 if(traverse->right != NULL)
  trav_inorder(traverse->right);
}

void trav_preorder(struct node *traverse)
{
 printf("%c",traverse->c);
 if(traverse->left != NULL)
  trav_preorder(traverse->left);
 if(traverse->right != NULL)
  trav_preorder(traverse->right);
}

void trav_postorder(struct node *traverse)
{    
 if(traverse->left != NULL)
  trav_postorder(traverse->left);
 if(traverse->right != NULL)
  trav_postorder(traverse->right);
 printf("%c",traverse->c);
}

struct node *root = NULL;

char stack[50];
int top = -1;
char pfx[50];
char ifx[50];

struct node *stack1[50];
int top1 = -1;

void push1(struct node *x)
{
 if(top == 49)
  printf("\nStack is full\n");
 else
  stack1[++top] = x;
}

struct node* pop1()
{
 if(top == -1)
  printf("\nStack is empty\n");
 else
  return stack1[top--];
}

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
 int i,k = 0,choice;
 char ch;
 printf("\nEnter infix expression ");
 scanf("%[^\n]%*c",ifx);
 for(i = 0;ifx[i] != '\0';i++)
 {
  if(ifx[i] == '(')
  {
   push(ifx[i]);
  }
  else if(ifx[i] >= 97 && ifx[i] <= 122)
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

 // Building expression tree
 
 i = 0;

 for(i = 0;pfx[i] != '\0';i++)
 {
  if(pfx[i] >= 97 && pfx[i] <= 122)
  {
   struct node *t = (struct node*)malloc(sizeof(struct node));
   t->c = pfx[i];
   t->left = t->right = NULL;
   push1(t);
  }
  else
  {
   struct node *x = pop1();
   struct node *y = pop1();
   
   struct node *t = (struct node*)malloc(sizeof(struct node));
   t->c = pfx[i];
   t->left = y;
   t->right = x;
   push1(t);
  }
 }
 root = pop1();
  
 printf("\nExpression tree is made\n");

 printf("\nMENU\n");
 printf("\n1. Preorder traversal\n2. Inorder traversal\n3. Postorder traversal\n");
 do
 {
  printf("\nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:trav_preorder(root);
          break;
   case 2:trav_inorder(root);
          break;
   case 3:trav_postorder(root);
          break;
   default:printf("\nInvalid choice\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch);
 }while(ch == 'y' || ch == 'Y');
}  
