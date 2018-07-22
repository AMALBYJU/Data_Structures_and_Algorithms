#include<stdio.h>
#include<stdlib.h>
struct node
{
 int num;
 struct node *prev;
 struct node *next;
};
struct node *head = NULL;
int n = 0;
 
void Insert(int ele,int pos)
{
  if(pos == 1)
  {
   struct node *new = (struct node *)malloc(sizeof(struct node));
   new->num = ele;
   new->prev = NULL;
   new->next = head;
   head = new;
  }
  else
  {
   struct node *cursor = (struct node*)malloc(sizeof(struct node));
   cursor = head;
   while(pos != 2)
   {
    cursor = cursor->next;
    pos--;
   }
   struct node *c1 = (struct node*)malloc(sizeof(struct node));
   c1->num = ele;
   c1->next = cursor->next;
   c1->prev = cursor;
   cursor->next = c1;
   if(c1->next != NULL)
    c1->next->prev = c1;
  }
 n++;
}
   
void Delete(int pos)
{
 if(head == NULL)
 {
  printf("\nEmpty list\n");
 }
 else
 {
  struct node *cursor = head;
  if(pos == 1)
  {
   head = head->next;
   if(head != NULL)
    head->prev = NULL;
   free(cursor);
   n--;
  }
  else
  {
   while(pos != 2)
   {
    cursor = cursor->next;
    pos--;
   }
   struct node *temp = cursor->next;
   cursor->next = temp->next;
   free(temp); 
   n--;
  }
 }
}

void traverse()
{
 struct node *cursor = head;
 printf("\nForwards\n");
 while(cursor->next != NULL)
 {
  printf("%d->",cursor->num);
  cursor = cursor->next;
 }
 printf("%d->\n",cursor->num);
 printf("\nBackwards\n");
 while(cursor != NULL)
 {
  printf("%d->",cursor->num);
  cursor = cursor->prev;
 }
}

void main()
{
 int choice,ch1,pos,ele;
 char ch;
 printf("\nDoubly linked list\n");
 printf("1. Insert\n2. Delete\n3. Traverse\n");
 do
 {
 printf("\nEnter choice "); 
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:printf("Enter element to insert ");
         scanf("%d",&ele);
         printf("Enter position \n1. Beginning\n2. Any position\n3. End\n");
         scanf("%d",&ch1);
         if(ch1 == 1)
          Insert(ele,1);
         else if(ch1 == 3)
          Insert(ele,n);
         else
         {
          printf("\nEnter position ");
          scanf("%d",&pos);
          Insert(ele,pos);
         }
         break;
  case 2:printf("\nEnter position to delete\n1. Beginning\n2. Any position\n3. End\n");
         scanf("%d",&ch1);
         if(ch1 == 1)
          Delete(1);
         else if(ch1 == 3)
          Delete(n);
         else
         {
          printf("\nEnter position ");
          scanf("%d",&pos);
          Delete(pos);
         }
         break;
  case 3:traverse();
         break;
  default:printf("\nInvalid input\n");
 }
 printf("\nDo you want to continue? (Y/N) ");
 scanf("%*c%c",&ch);
 }while(ch == 'Y' || ch == 'y');
}
