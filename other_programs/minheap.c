#include<stdio.h>
#include<stdlib.h>

int arr[50];

void insert(int num)
{
 int i;
 for(i = 0;i<50;i++)
 {
  if(arr[i] == 0)
  {
   arr[i] = num;
   break;
  }
 } 
 while(i > 0 && (arr[(i-1)/2] > arr[i]))
 {
   int t = arr[i];
   arr[i] = arr[(i-1)/2];
   arr[(i-1)/2] = t;
   i = (i-1)/2;
 }
}

void deleteUtil(int i)
{
 if(arr[i] == 0)
  return;									
 else
 {            
  if(arr[i] > arr[2*i+1])
  {
    int t = arr[i];
    arr[i] = arr[2*i+1];
    arr[2*i+1] = t;       
    deleteUtil(arr[2*i+1]);
  }
  else
  {
    int t = arr[i];
    arr[i] = arr[2*i+2];
    arr[2*i+2] = t;       
    deleteUtil(arr[2*i+2]);
  }
 }
 return;
}

void delete()
{
 if(arr[0] == 0)
  printf("\nHeap is empty\n");
 else
 {
  int i;
  for(i=50;i>=0;i--)
   if(arr[i] != 0)
    break; 
  printf("\nDeleted element is %d\n",arr[0]);
  arr[0] = arr[i];
  arr[i] = 0;
  deleteUtil(0);
 }
}




void main()
{
 int choice,ele;
 char ch;
 printf("\nMINHEAP\n");
 printf("1. Insert\n2. Delete\n3. Display\n");
 int i;
 for(i=0;i<50;i++)
  arr[i] = 0;
 do
 {
  printf("Enter choice ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:printf("Enter element to insert ");
           scanf("%d",&ele);
           insert(ele);
           break;
    case 2:delete();                                                                           
           break;
    case 3:printf("\nDisplaying elements\n");
           for(i=0;arr[i]!=0;i++)
            printf("%d ",arr[i]);
           break;
    default:printf("\nInvalid choice\n");
           break;
  }
  printf("Do you want to continue? (Y/N) ");
  scanf("%*c%c",&ch);
 }while(ch == 'y' || ch == 'Y');
} 
  
     
