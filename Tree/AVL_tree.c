#include<stdio.h>
#include<stdlib.h>

struct node
{
 int num;
 struct node *left;
 struct node *right;
};

struct node *root;
struct node *cursor = NULL;

struct node* leftrotate(struct node *root)
{
 struct node *x = root->right->left;
 struct node *y = root->right;
 
 y->left = root;
 root->right = x;
 return y;
}

struct node* rightrotate(struct node *root)
{
 struct node *x = root->left;
 struct node *y = root->left->right;

 x->right = root;
 root->left = y;
 return x;
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

struct node* insert(struct node *root,int ele)
{
 if(root == NULL)
 {
  struct node *ptr = (struct node*)malloc(sizeof(struct node));
  ptr->num = ele;
  ptr->left = ptr->right = NULL;
  root = ptr;
  return root;
 }
 else if(ele < root->num)
  root->left = insert(root->left,ele);
 else if(ele > root->num)
  root->right = insert(root->right,ele);
 else
 { 
  printf("\nDuplicate elements not allowed\n");
  return root;
 }
 if(findheight(root->left)-findheight(root->right) > 1)  
 {
  if(ele < root->left->num)
   return rightrotate(root);
  else
  {
   root->left = leftrotate(root->left);
   return rightrotate(root);
  }
 }
 else if(findheight(root->left) - findheight(root->right) < -1)
 {
  if(ele > root->right->num)
   return leftrotate(root);
  else
  {
   root->right = rightrotate(root->right);
   return leftrotate(root);
  }
 }
 return root;
}
 void trav_inorder(struct node *traverse)
{
 if(traverse->left != NULL)
  trav_inorder(traverse->left);
 if(traverse != NULL)
  printf("%d ",traverse->num);
 if(traverse->right != NULL)
  trav_inorder(traverse->right);
}

void trav_preorder(struct node *traverse)
{
 if(traverse != NULL)
 printf("%d ",traverse->num);
 if(traverse->left != NULL)
  trav_preorder(traverse->left);
 if(traverse->right != NULL)
  trav_preorder(traverse->right);
}

void trav_postorder(struct node *traverse)
{
 if(traverse != NULL)
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
 if(findheight(root->left)-findheight(root->right) > 1)  
 {
  if(ele < root->left->num)
   return rightrotate(root);
  else
  {
   root->left = leftrotate(root->left);
   return rightrotate(root);
  }
 }
 else if(findheight(root->left) - findheight(root->right) < -1)
 {
  if(ele > root->right->num)
   return leftrotate(root);
  else
  {
   root->right = rightrotate(root->right);
   return leftrotate(root);
  }
 }
 return root;
}

void main()
{
 int ele,x,choice;
 char ch;
 printf("\nAVL Tree\n");
 printf("1. Insert\n2. Delete\n3. Preorder traversal\n4. Inorder traversal\n5. Postorder traversal\n6. Find height of tree\n");
 do
 {
  printf("\nEnter your choice ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:printf("Enter the element ");
          scanf("%d",&ele);
          root = insert(root,ele);
          break;
   case 2:printf("Enter the element to delete ");
          scanf("%d",&ele);
          delete(root,ele);
          break;
   case 3:trav_preorder(root);
          break;
   case 4:trav_inorder(root);
          break;
   case 5:trav_postorder(root);
          break;
   case 6:printf("\nThe height of the tree is %d\n",findheight(root));
          break;
   default:printf("\nInvalid input\n");
  }
  printf("\nDo you want to continue? (Y/N) ");
  scanf("%*c%c",&ch);
 }while(ch == 'y' || ch == 'Y');
} 
