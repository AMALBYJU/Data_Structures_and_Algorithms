#include<stdio.h>
#include<stdlib.h>
struct node 
{
 int num; 
 struct node *next;
};
int top = -1;
struct node *head = NULL;
struct node *temp = NULL;
void insert(int ele,int pos)
{

 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
   printf("\nNot enough space for allocation\n");
   return ;
 }
 else
 {
  if(head == NULL || pos == 1)
  {
   ptr->num = ele;
   ptr->next = head;
   head = ptr;
  }
  else
  {
   struct node *cursor = head;
   while(pos != 2)
   {
    cursor = cursor->next; 
    --pos;
   }
   ptr->num = ele;
   ptr->next = cursor->next;
   cursor->next = ptr;
  }
 }
}

void delete(int pos)
{
 if(head == NULL)
  printf("\nList is empty\n");
 else
 {
  if(pos == 1)
  {
   struct node *temp = head;
   head = head->next;
   free(temp);
  }
  struct node *cursor = head;
  while(pos != 2)
  {
   --pos;
   cursor = cursor->next;
  }
  struct node *temp = cursor->next;
  cursor->next = cursor->next->next;
  free(temp);
 }
}

void reverse()
{
 if(head == NULL)
  printf("\nList is empty\n");
 else
 {
  struct node *prev = NULL,*current = head,*nex = head->next;
  while(current != NULL)
  {
   nex = current->next;
   current->next = prev;
   prev = current;
   current = nex;
  }
  head = prev;
 }
}

void recrev(struct node *cursor)
{
 if(cursor == NULL || cursor->next == NULL)
 {  
   temp = cursor;
   return;
 }
 else
 {
  recrev(cursor->next);
  cursor->next->next = cursor;
  if(cursor == head)
  {
   cursor->next = NULL;
   head = temp;
  }
 }
} 

void push(struct node *ele)
{
 if(top == 29)
  printf("\nStack is full\n");
 else
  S[++top] = ele;
}

struct node* pop()
{
 if(top == -1)
  printf("\nStack is empty\n");
 else
  return S[top--];
}

void srev(struct node *cursor)
{
 if(cursor->next == NULL)
 {
  temp = cursor;
  temp->next = pop();
  return;
 }
 else
 {
  push(cursor);
  srev(cursor->next);
  if(head == cursor)
  {
   cursor->next = NULL;
   head = temp;
   return;
  }
  cursor->next = pop();
 }
}
  

void display()
{
 if(head == NULL)
  printf("\nList is empty\n");
 else
 {
  struct node *cursor = head;
  for(;cursor != NULL;cursor = cursor->next)
   printf("%d->",cursor->num);
 }
} 

void main()
{
 int a[20];
 int choice,ele,pos;
 char ch;
 printf("\nMENU\n1. Insert\n2. Delete\b3. Reverse\n4. Display\n");
 do
 {
  printf("\nEnter choice ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("Enter element to enter and position\n");
           scanf("%d%d",&ele,&pos);
           insert(ele,pos);
           break;
    case 2:delete(pos);
           break; 
    case 3:srev(head);
           break; 
    case 4:display();
           break;
    default:printf("\nInvalid input\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch);
 }while(ch == 'y' || ch == 'Y');
}
