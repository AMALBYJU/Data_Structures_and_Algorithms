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

int front = -1,rear = -1;

void enqueue(int q[],int v,int ele)
{
 if(front == (rear+1) % v)
  printf("\nQueue is full\n");
 else if(rear == -1)
 {
  front = rear = 0;
  q[rear] = ele;
 }
 else
 {
  q[(rear+1)%v] = ele;
  rear = (rear+1)%v;
 }
}

int dequeue(int q[],int v)
{
 if(front == -1)
 {
  printf("\nQueue is empty\n");
 }
 else if(front == rear)
 {
   int temp = front;
   front = rear = -1;
   return q[temp];
 }
 else
 {
   int temp = front;
   front = (front+1)%v; 
   return q[temp];
 }
}


void BFS(struct graph* G,int s)
{
 int q[G->vertices];
 enqueue(q,G->vertices,s);
 int *visited = (int*)malloc(G->vertices * sizeof(int));
 int i;
 for(i=0;i < G->vertices;i++)
 {
  visited[i] = 0;
 }
 
 visited[s] = 1;
 

  struct node *crawl;
 
  while(front != -1)
  {
   s = dequeue(q,G->vertices);
   printf("%d->",s);
   crawl = G->array[s].head;
   while(crawl)
   {
    if(!visited[crawl->num])
    {
     enqueue(q,G->vertices,crawl->num);
     visited[crawl->num] = 1;
    }
    crawl = crawl->next;
   }
  }
   
}
void DFSutil(struct graph *G,int s,int visited[])
{
 printf("%d->",s);
 visited[s] = 1;
 
 struct node *crawl = G->array[s].head;
 
 while(crawl)
 {
  if(visited[crawl->num] != 1)
  {
   DFSutil(G,crawl->num,visited);
  }
  crawl = crawl->next;
 }
}  

void DFS(struct graph *G,int s)
{
 int *visited = (int*)malloc(G->vertices * sizeof(int));
 int i;
 for(i=0;i< G->vertices;i++)
  visited[i] = 0;
 
 DFSutil(G,s,visited);
 
 for(i = 0;i < G->vertices;i++)
 {
  if(visited[i] == 0)
   DFSutil(G,i,visited);
 }
}


void printallpathsutil(struct graph *G,int s,int d,int visited[],int path[],int path_index)
{
 visited[s] = 1;
 path[path_index] = s;
 path_index++;
 int i;
 
 if(s == d)
 {
   for(i = 0;i<path_index;i++)
    printf("%d->",path[i]);
   printf("\n");
 }
 else
 {
  struct node *crawl = G->array[s].head;
  while(crawl)
  {
   if(visited[crawl->num] == 0)
   {
    printallpathsutil(G,crawl->num,d,visited,path,path_index);
   }
   crawl = crawl->next;
  }
 }
 visited[s] = 0;
 path_index--;
}    

   
void printallpaths(struct graph *G,int s,int d)
{
 int *visited = (int*)malloc(G->vertices * sizeof(int));
 int i;
 for(i=0;i< G->vertices ; i++)
  visited[i] = 0;
 int *path = (int*)malloc( G->vertices * sizeof(int)); 
 int path_index = 0;
 
 printallpathsutil(G,s,d,visited,path,path_index);
}


void printgraph(struct graph *G)
{
 int i;
 for(i = 0;i < G->vertices;i++)
 {
  printf("\nAdjacency list of vertex %d\n",i);
  struct node *crawl = G->array[i].head; 
  while(crawl)
  {
   printf("%d->",crawl->num);
   crawl = crawl->next;
  }
 }
}

int top = -1;

void push(int stack[],int ele,struct graph *G)
{
 if(top == (G->vertices -1))
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

void topological_sort_util(struct graph *G,int visited[],int s,int stack[])
{
 
 visited[s] = 1;
 
 struct node *crawl = G->array[s].head;
 
 while(crawl)
 {
  if(visited[crawl->num] == 0)
  {
   topological_sort_util(G,visited,crawl->num,stack);
  }
  crawl = crawl->next;
 }
 push(stack,s,G);
} 
  

void topological_sort(struct graph *G)
{
 int *visited = (int*)malloc( G->vertices * sizeof(int));
 int i;
 for(i=0 ; i< G->vertices ; i++)
 {
  visited[i] = 0;
 }
 
 int stack[G->vertices];
 
 for(i=0;i< G->vertices ; i++)
 { 
  if(visited[i] == 0)
   topological_sort_util(G,visited,i,stack);
 }
 
 while(top != -1)
 {
  int x = pop(stack);
  printf("%d ",x);
 } 
 
}  

void main()
{
 struct graph *G = creategraph(6);
 addedge(G,5,0);
 addedge(G,5,2);
 addedge(G,2,3);
 addedge(G,3,1);
 addedge(G,4,0);
 addedge(G,4,1);
 printf("Breadth First Search\n");
 BFS(G,2);
 printf("\nDepth First Search\n");
 DFS(G,2);
 printf("\nTopological sort\n");
 topological_sort(G);
 printf("\n");
 printf("\nPrinting all paths from 2 to 5\n");
 printallpaths(G,2,5);
 printgraph(G);
 
}  
