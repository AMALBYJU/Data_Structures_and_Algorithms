#include<stdio.h>
#include<stdlib.h>

struct node
{
 int num;
 struct node *next;
};

struct node *head = NULL;
struct node *new = NULL;

long int change(struct node *ptr)
{
 return ptr;
}

void create()
{
 int n,ele,i;
 printf("Enter the number of elements to be inserted ");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  printf("Enter the element %d ",i);
  scanf("%d",&ele);
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  if(i == 1)
  {
   new = (struct node*)malloc(sizeof(struct node));
   new->next = NULL;
   new->num = ele;
   head = new;
  }
  else
  {
   temp->num = ele;
   new->next = change(new->next)^change(temp);
   temp->next = change(new)^change(NULL);
   new = temp;
  }
 }
}

void Insert(int ele,int pos)
{ 
  int i;
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  if(head == NULL)
  {
   ptr->num = ele;
   ptr->next = NULL;
   head = ptr;
  }
  else
  {
   if(pos == 1)
   {
    ptr->num = ele;
    ptr->next = head;
    head->next = change(ptr)^change(head->next);
    head = ptr;
   }
   else
   {
    ptr = head;
    struct node *prev = NULL;
    struct node *ptr1 = head->next;
    for(i=2;i<pos;i++)
    {
     struct node *temp = ptr;
     ptr1 = change(ptr)^change(ptr1->next);
     ptr = change(prev)^change(ptr->next);
     prev = temp;
    }
    struct node *ins = (struct node*)malloc(sizeof(int));
    ins->num = ele;
    ins->next = change(ptr)^change(ptr1);
    if(ptr1 != NULL)
     ptr1->next = change(ins)^(change(ptr)^change(ptr1->next));
    ptr->next = change(prev)^change(ins);
   }
  }
 }
      
        


void Delete(int pos)
{
 int i;
 if(head == NULL)
  printf("List is empty\n");
 else
 {
  if(pos == 1)
  {
   struct node *temp = head;
   head = head->next;
   head->next = change(NULL)^(change(temp)^change(head->next));
   free(temp);
  }
  else
  {
   struct node *prev = NULL;
   struct node *ptr = head;
   struct node *ptr1 = head->next;
   for(i=2;i<pos;i++)
   {
    struct node *temp = ptr;
    ptr1 = change(ptr)^change(ptr1->next);
    ptr = change(prev)^change(ptr->next);
    prev = temp;
   }
   ptr->next = change(prev)^(change(ptr)^change(ptr1->next));
   prev = change(ptr)^change(ptr1->next);
   if(prev != NULL)
    prev->next = change(ptr)^(change(ptr1)^change(prev->next));
   free(ptr1);
  }
 }
}

void traverse()
{
 if(head == NULL)
  printf("\nList is empty\n");
 else
 {
  struct node *t = head;
  struct node *t1 = head->next;
  printf("\n%d->",head->num);
  while(t1 != NULL)
  {
   printf("%d->",t1->num);
   struct node *temp = t1;
   t1 = change(t1->next)^change(t);
   t = temp;
  }
 }
}

void main()
{
 int choice,ele,pos;
 char ch;
 printf("\nLinked list\n");
 printf("1. Create list\n2. Insert elements\n3. Delete an element\n4. Traverse the list\n");
 do
 {
 printf("\nEnter choice ");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:create();
         break;
  case 2:printf("\nEnter element to insert ");
         scanf("%d",&ele);
         printf("\nEnter position ");
         scanf("%d",&pos);
         Insert(ele,pos);
         break;
  case 3:printf("\nEnter position to delete ");
         scanf("%d",&pos);
         Delete(pos);
         break;
  case 4:traverse();
         break;
  default:printf("\nInvalid value\n");
 }
 printf("\nDo you want to continue? (Y/N) ");
 scanf("%*c%c",&ch);
 }while(ch == 'Y' || ch == 'y');
}
