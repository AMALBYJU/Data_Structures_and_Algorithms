#include<stdio.h>
#include<stdlib.h>

struct node
{
 int num;
 struct node *next;
};

struct adjlist
{
 struct node *head;
};

struct graph
{
 int vertices;
 struct adjlist *array;
};

struct node *createnode(int num)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 ptr->num = num;
 ptr->next = NULL;
 return ptr;
}

struct graph* creategraph(int v)
{
 struct graph *G = (struct graph*)malloc(sizeof(struct graph));
 G->array = (struct adjlist*)malloc(v*sizeof(struct adjlist));
 G->vertices = v;
 int i;
 for(i=0;i<v;i++)
 {
  G->array[i].head = NULL;
 }
 return G;
}

void addedge(struct graph *G,int src,int dest)
{
 struct node *ptr = createnode(dest);
 ptr->next = G->array[src].head;
 G->array[src].head = ptr; 
}

void DFSUtil(struct graph *G,int s,int visited[])
{
 printf("%d->",s);
 visited[s] = 1;
 
 struct node *crawl = G->array[s].head;
 
 while(crawl)
 {
  if(visited[crawl->num] != 1)
  {
   DFSUtil(G,crawl->num,visited);
  }
  crawl = crawl->next;
 }
}  

int top = -1;

void push(int stack[],int ele,int v)
{
 if(top == (v -1))
  printf("\nStack is full\n");
 else
  stack[++top] = ele;
}

int pop(int stack[])
{
 if(top == -1)
  printf("\nStack is empty\n");
 else
  return stack[top--];
}

void stackorder(int s,struct graph *G,int stack[],int visited[])
{

 visited[s] = 1;
 
 struct node *crawl = G->array[s].head;
 
 while(crawl)
 {
  if(visited[crawl->num] != 1)
  {
   stackorder(crawl->num,G,stack,visited);
  }
  crawl = crawl->next;
 }
 push(stack,s,G->vertices);
}  

struct graph *transpose(struct graph *G)
{
 int i;
 struct graph *g = creategraph(G->vertices);
 struct node *crawl;
 for(i = 0;i< G->vertices ; i++)
 {
  crawl = G->array[i].head;
  while(crawl)
  {
   addedge(g,crawl->num,i);
  }
 }
 return g;
}  

void SCC(struct graph *G)
{
 int visited[G->vertices];
 int stack[G->vertices];
 
 int i;
 
 for(i=0;i< G->vertices; i++)
 {
  visited[i] = 0;
 }
 
 for(i=0;i< G->vertices; i++)
 {
  if(visited[i] == 0)
  {
   stackorder(i,G,stack,visited);
  }
 }
 
 struct graph *g = transpose(G);
 
 for(i=0;i< G->vertices ;i++)
  visited[i] = 0;
  
 while(top != -1)
 {                             .as,d.d,.a
  int x = pop(stack);  
   if(visited[x] == 0)
   {
    DFSUtil(g,x,visited);
    printf("\n");
   }
 } 
} 

void main()
{
 struct graph *G = creategraph(5);
 addedge(G,1, 0);
 addedge(G,0, 2);
 addedge(G,2, 1);
 addedge(G,0, 3);
 addedge(G,3, 4);
 
 printf("Following are strongly connected components in "
            "given graph \n");
 SCC(G); 
}
