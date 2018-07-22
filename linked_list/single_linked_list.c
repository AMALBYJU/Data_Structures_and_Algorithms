#include<stdio.h>
#include<stdlib.h>
struct node
{
 int num;
 struct node *next;
};
struct node *head = NULL;
struct node* create(int n)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
  printf("Not enough space for allocation\n");
  exit(0);
 }
 ptr->num = n;
 ptr ->next = head;
 head = ptr;
}
void traverse(struct node *head)
{
 if(head == NULL)
  printf("List is empty\n");
 else
 {
  struct node *cursor = head;
  while(cursor != NULL)
  {
   printf("%d->",cursor->num);
   cursor = cursor->next;
  }
 }
} 
void Delete(int n)
{ 
 int flag = 0;
 struct node *cursor = head;
 if(cursor == NULL)
 { 
  printf("Empty linked list \n");
  exit(0);
 }
 else
 {
  if(head->num == n)
  {
   flag = 1;	
   struct node * temp = (struct node*)malloc(sizeof(struct node));
   temp = head;
   head = head->next;
   free(temp);
  }
  while(cursor->next!=NULL) 
  {
   if(cursor->next->num == n)
   {
    struct node *new = cursor->next;
    cursor->next = new->next;
    free(new);
    flag = 1;
    break;
   }
   cursor = cursor->next;
  }
  
 }
 if(flag == 0)
  printf("\nElement not found\n");
} 
  
void main()
{ 
 char ch;
 do
 {
 int n,ele;
 printf("\nLinked list\n");
 printf("1. Insert an element\n2. Delete an element\n3. Traverse linked list\n");
 scanf("%d",&n);
 switch(n)
 {                             
  case 1:printf("Enter an element ");
         scanf("%d",&ele);
         create(ele);
         break;
  case 2:printf("Enter an element to delete ");
         scanf("%d",&ele);
         Delete(ele);
         break;
  case 3:printf("\nDisplaying the elements ");
         traverse(head);
 }
 printf("\nDo you want to continue? (Y/N) ");
 scanf("%*c%c",&ch);
 }while(ch=='Y'||ch=='y');
}
                                                                                
