#include<stdio.h>
#include<stdlib.h>
/*
Program to check whether tree is
1. Full
2. Perfect
3. Complete 
and to find height of tree.
*/
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
  { 
   printf("Enter 0 to enter left node and 1 to enter right node ");
   scanf("%d",&choice);
   if(choice == 0 && cursor->left == NULL)
   {
    ptr->num = ele;
    cursor->left = ptr;
    ptr->left = NULL;
    ptr->right = NULL;
    return;
   }
   else if(choice == 1 && cursor->right == NULL)
   {
    ptr->num = ele;
    cursor->right = ptr;
    ptr->left = NULL;
    ptr->right = NULL;
    return;
   }
   else if(choice == 0)
    cursor = cursor->left;
   else
    cursor = cursor->right;
  }  
 }
}

int check_full(struct node* root)
{
 if(root == NULL)
  return 1;
 else if(root->left == NULL && root->right == NULL)
  return 1;
 else if(root->left == NULL || root->right == NULL)
  return 0;
 else 
  return check_full(root->left) && check_full(root->right);
}

int findheight(struct node *root)
{
 if(root == NULL)
  return -1;
 else
 {
  int x = findheight(root->left);
  int y = findheight(root->right);
  if(x>y)
   return x+1;
  else
   return y+1;
 }
}

int checkperfect(struct node *root,int level,int height)
{
 if(root == NULL)
  return 1;
 else if(root->left ==NULL && root->right == NULL)
  if(height == level)
   return 1;
  else
   return 0;  
 else if(root->left == NULL || root->right == NULL)
  return 0;
 else
  return (checkperfect(root->left,level+1,height) && checkperfect(root->right,level+1,height));
}

 
int iscomplete(struct node *root,int level,int height)
{
 if(root == NULL)
  return 1;
 else if(root->left == NULL && root->right == NULL)
 {
   if(height == level)
    return 1;
   else
    return 0;
 } 

 else
 {
   if( iscomplete(root->left,level+1,height) == 0 && iscomplete(root->right,level+1,height) == 1)
    return 0;
   else
    return 1;
 }
}  
 
 void trav_inorder(struct node *traverse)
{
 if(traverse->left != NULL)
  trav_inorder(traverse->left);
 printf("%d ",traverse->num);
 if(traverse->right != NULL)
  trav_inorder(traverse->right);
}

void trav_preorder(struct node *traverse)
{
 printf("%d ",traverse->num);
 if(traverse->left != NULL)
  trav_preorder(traverse->left);
 if(traverse->right != NULL)
  trav_preorder(traverse->right);
}

void trav_postorder(struct node *traverse)
{
 printf("%d",traverse->num);    
 if(traverse->left != NULL)
  trav_postorder(traverse->left);
 if(traverse->right != NULL)
  trav_postorder(traverse->right);
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

void main()
{
 int ele,x,choice;
 char ch;
 printf("\nBinary Search Tree\n");
 printf("1. Insert\n2. Delete\n3. Check if tree is a full binary tree\n4. Check if binary tree is perfect\n5. Check if binary tree is complete\n6. Preorder traversal\n7. Inorder traversal\n8. Postorder traversal\n9. Find height of tree\n");
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
   case 3:x = check_full(root);
          if(x == 1)
           printf("\nThe tree is a full binary tree\n");
          else
           printf("\nThe tree is not a full binary tree\n");
          break;
   case 4:x = checkperfect(root,0,findheight(root));
          if(x == 1)
           printf("\nThe tree is a perfect binary tree\n");
          else
           printf("\nThe tree is not a perfect binary tree\n");
          break;
   case 5:x = iscomplete(root,0,findheight(root));
          if(x == 1)
           printf("\nThe tree is a complete binary tree\n");
          else
           printf("\nThe tree is not a complete binary tree\n");
          break;
   case 6:trav_preorder(root);
          break;
   case 7:trav_inorder(root);
          break;
   case 8:trav_postorder(root);
          break;
   case 9:printf("\nThe height of the tree is %d\n",findheight(root));
          break;
   default:printf("\nInvalid input\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch);
 }while(ch == 'y' || ch == 'Y');
} 
 
  
