#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int num;
  struct node *next;
};
struct node *head = NULL;
int n = 0;

void Insert(int ele,int pos)
{
 struct node *p1 = (struct node*)malloc(sizeof(struct node));
 struct node *cursor = head;
 if(head == NULL)
 {
  p1->num = ele;
  p1->next = NULL;
  head = p1;
 }
 else
 {
  if(pos == 1)
  {
   while(cursor->next != head || cursor->next != NULL)
    cursor = cursor->next;
   p1->num = ele;
   p1->next = head;
   cursor->next = p1;
   head = p1;
  }
  else
  {
   while(pos != 2)
   {
    cursor = cursor->next;
    pos--;
   }
   p1->num = ele;
   p1->next = cursor->next;
   cursor->next = p1;
  }
 n++;
 }
}

void Delete(int pos)
{
 struct node *cursor = head;
 if(head == NULL)
  printf("\nList is empty\n");
 else if(pos == 1)
 {
  while(cursor->next != head)
   cursor = cursor->next;
  struct node *ptr = head;
  cursor->next = cursor->next->next;
  free(ptr);
  n--;
 }
 else
 {
  while(pos != 2)
  {
   cursor = cursor->next;
   pos--;
  }
  struct node *ptr = cursor->next;
  cursor->next = cursor->next->next;
  free(ptr);
  n--;
 }
}

void traverse()
{
 struct node *cursor = head;
 while(cursor->next != head)
 {
  printf("%d->",cursor->num);
  cursor = cursor->next;
 }
 printf("%d",cursor->num);
 
}

void main()
{
 int choice,ch1,ele,pos;
 char ch;
 printf("\nLinked list\n");
 printf("1. Insert element\n2. Delete element\n3. Display element\n");
 do
 {
  printf("\nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("Enter element to insert ");
          scanf("%d",&ele);
          printf("Enter position \n1. Beginning\n2. Any position\n3. End\n");
          scanf("%d",&ch1);
          if(ch1 == 1)
           Insert(ele,1);
          else if(ch == 3)
           Insert(ele,n);
          else
          {
           printf("Enter a valid position ");
           scanf("%d",&pos);
           Insert(ele,pos);
          }
          break;
   case 2:printf("Enter position to delete ");
          scanf("%d",&pos);
          Delete(pos);
          break;
   case 3:traverse();
          break;
   default:printf("\nInvalid input\n");
  }
 printf("\nDo you want to continue? (Y/N) ");
 scanf("%*c%c",&ch);
 }while(ch == 'Y' || ch == 'y');
}
     
   
   
  
