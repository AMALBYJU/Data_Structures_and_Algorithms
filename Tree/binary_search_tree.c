#include<stdio.h>
#include<stdlib.h>
struct node
{
 int num;
 struct node *left;
 struct node *right;
};

struct node *traverse = NULL;
struct node *root = NULL;

void insert(int ele)
{
 struct node *temp = (struct node*)malloc(sizeof(struct node));
 if(root == NULL)
 {
  temp->num = ele;
  temp->left = NULL;
  temp->right = NULL;
  root = temp;
 }
 else
 {
  struct node *current = root;
  struct node *parent = NULL;
  while(current != NULL)
  {
   parent = current;
   if(current->num < ele)
   {
    current = current->right;
   }
   else if(current->num > ele)
    current = current->left;
   else
   {
    printf("\nDuplicate element is not inserted in BST\n");
    return;
   } 
  }
  if(ele > parent->num)
   parent->right = temp;
  else if(ele < parent->num)
   parent->left = temp;
 
  temp->num = ele;
  temp->left = NULL;
  temp->right = NULL;
 }
}

void search(int ele)
{
 if(root == NULL)
  printf("\nTree is empty\n");
 else
 {
  struct node *current = root;
  while(current != NULL)
  { 
   if(current->num > ele)
    current = current->left;
   else if(current->num < ele)
    current = current->right;
   else
   {
    printf("Element found");
    return;
   }
  }
  printf("\nElement not found\n");
 }
}

struct node* findmin(struct node *ptr)
{
 while(ptr->left != NULL)
  ptr = ptr->left;
 return ptr;
}
 
struct node* delete(struct node *root,int ele)
{
 if(root == NULL)
 {
  printf("\nElement not found\n");
  return root;
 }
 else if(ele < root->num)
  root->left = delete(root->left,ele);
 else if(ele > root->num)
  root->right = delete(root->right,ele);
 else
 {
  if(root->left == NULL && root->right == NULL)
  {
   free(root);
   root = NULL;
   return root;
  }
  else if(root->left == NULL)
  {
   struct node *temp = root;
   root = root->right;
   free(temp);
   return root;
  }
  else if(root->right == NULL)
  {
   struct node *temp = root;
   root = root->left;
   free(temp);
   return root;
  }
  else
  {
   struct node *temp = findmin(root->right);
   root->num = temp->num;
   root->right = delete(root->right,temp->num);
   return root;
  }
 }
}
  
void trav_inorder(struct node *traverse)
{
 if(traverse != NULL)
 {
  if(traverse->left != NULL)
   trav_inorder(traverse->left);
   printf("%d ",traverse->num);
  if(traverse->right != NULL)
   trav_inorder(traverse->right);
 }
}

void trav_preorder(struct node *traverse)
{
 if(traverse != NULL)
 {
   printf("%d ",traverse->num);
  if(traverse->left != NULL)
   trav_preorder(traverse->left);
  if(traverse->right != NULL)
   trav_preorder(traverse->right);
 }
}

void trav_postorder(struct node *traverse)
{
 if(traverse != NULL)
 {
  if(traverse->left != NULL)
   trav_postorder(traverse->left);
  if(traverse->right != NULL)
   trav_postorder(traverse->right);
  printf("%d",traverse->num); 
 }
}

void main()
{
 int ele,choice;
 char ch;
 printf("\nBinary Search Tree\n");
 printf("1. Insert\n2. Delete\n3. Search\n4. Preorder traversal\n5. Inorder traversal\n6. Postorder traversal\n");
 do
 {
  printf("\nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("Enter the element ");
          scanf("%d",&ele);
          insert(ele);
          break;
   case 2:printf("Enter the element to delete ");
          scanf("%d",&ele);
          delete(root,ele);
          break;
   case 3:printf("Enter the element to search ");
          scanf("%d",&ele);
          search(ele);
          break;
   case 4:trav_preorder(root);
          break;
   case 5:trav_inorder(root);
          break;
   case 6:trav_postorder(root);
          break;
   default:printf("\nInvalid input\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch);
 }while(ch == 'y' || ch == 'Y');
} 





