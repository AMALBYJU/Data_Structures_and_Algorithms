//Shortest path for DAG

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int top = -1;

struct node
{
 int num;
 int weight;
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

struct node *createnode(int v,int weight)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 ptr->num = v;
 ptr->weight = weight;
 ptr->next = NULL;
 return ptr;
}

struct graph *creategraph(int v)
{
 struct graph *G = (struct graph*)malloc(sizeof(struct graph));
 G->vertices = v;
 G->array = (struct adjlist*)malloc(G->vertices * sizeof(struct adjlist));
 int i;
 for(i=0;i< G->vertices ; i++)
  G->array[i].head = NULL;
 return G;
}

void addedge(struct graph *G,int src,int dest,int weight)
{
 struct node *ptr = createnode(dest,weight);
 ptr->next = G->array[src].head;
 G->array[src].head = ptr;
}

void push(int stack[],int v,int ele)
{
 if(top == v-1)
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

void topologicalsortutil(struct graph *G,int v,int visited[],int stack[])
{
 visited[v] = 1;
 struct node *crawl = G->array[v].head;
 
 while(crawl)
 {
  if(visited[crawl->num] == 0)
   topologicalsortutil(G,crawl->num,visited,stack);
  crawl = crawl->next;
 }
 push(stack,G->vertices,v);
}

void printarr(int A[],int v)
{
 int i;
 for(i = 0;i < v ; i++)
 {
  if(A[i] == INT_MAX)
   printf("INF - %d\n",i);
  else
  printf("%d - %d\n",A[i],i);
 } 
}

void shortestpath(struct graph *G,int src)
{
 int visited[G->vertices];
 int stack[G->vertices];
 int dist[G->vertices];
 int i;
 
 for(i=0;i< G->vertices ; i++)
 {
  visited[i] = 0;
  dist[i] = INT_MAX;
 }
 
 dist[src] = 0; 
 
 for(i=0;i< G->vertices ; i++)
  if(visited[i] == 0)
   topologicalsortutil(G,i,visited,stack);
 
 while(top != -1)
 {
  int x = pop(stack);
  
  struct node *crawl = G->array[x].head;
  
  if(dist[x] != INT_MAX)
  {
   while(crawl)
   {
    if((dist[x] + crawl->weight) < dist[crawl->num])
    {
     dist[crawl->num] = dist[x] + crawl->weight;
    }
    crawl = crawl->next;  
   }
  }  
 }
 printarr(dist,G->vertices);
}

int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    struct graph *g = creategraph(6);
    addedge(g,0, 1, 5);
    addedge(g,0, 2, 3);
    addedge(g,1, 3, 6);
    addedge(g,1, 2, 2);
    addedge(g,2, 4, 4);
    addedge(g,2, 5, 2);
    addedge(g,2, 3, 7);
    addedge(g,3, 4, -1);
    addedge(g,4, 5, -2);
 
    int s = 1;
    printf("Following are shortest distances from source %d\n",s);
    shortestpath(g,s);
 
    return 0;
}  
