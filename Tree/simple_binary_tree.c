#include<stdio.h>
struct node
{
 int num;
 struct node *left;
 struct node *right;
};

struct node *root = NULL;
struct node *cursor = NULL;
void insert(int ele)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 if(root == NULL)
 {
  ptr->num = ele;
  ptr->left = NULL; 
  ptr->right = NULL;
  root = ptr;
 }
 else
 {
  int choice;
  cursor = root;
  while(cursor != NULL)  
  printf("Enter 0 to enter left node and 1 to enter right node ");
  scanf("%d",choice);
  if(choice == 0 && cursor->left == NULL)
  {
   ptr->num = ele;
   cursor->left = ptr;
   ptr->left = NULL;
   ptr->right = NULL;
  }
  else if(choice == 1 && cursor->right == NULL)
  {
   ptr->num = ele;
   cursor->right = ptr;
   ptr->left = NULL;
   ptr->right = NULL;
  }
  else if(choice == 0)
   cursor = cursor->left;
  else
   cursor = cursor->right;
 }
}

struct node* findleaf(struct node *cursor)
{
 while(cursor->left != NULL)
  cursor = cursor->left;
 return cursor;
}

struct node* delete(struct node *root,int ele)
{
 if(root == NULL)
  return root;
 else if(ele > root->num)
  root->right = delete(root->right,ele);
 else if(ele < root->num)
  root->left = delete(root->left,ele);
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
   struct node *temp = findleaf(root);
   root->num = temp->num;
   root->right = delete(root->right,temp->num);   
   return root;
  } 
 }
}

struct
