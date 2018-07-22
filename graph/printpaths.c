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

struct node *createnode(int v)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 ptr->num = v;
 ptr->next = NULL;
 return ptr;
}

void addedge(struct graph *G,int src,int dest)
{
 struct node *ptr = createnode(dest); 
 ptr->next = G->array[src].head;
 G->array[src].head = ptr;
 
 ptr = createnode(src);
 ptr->next = G->array[dest].head;
 G->array[dest].head = ptr;
}

void printpath(int path[],int n)
{
 int i;
 for(i=0;i<=n;i++)
  printf("%d->",path[i]);
}

void printallpathsutil(struct graph *G,int src,int dest,int inter,int in,int visited[],int path[],int pathindex)
{
 path[++pathindex] = src;
 visited[src] = 1;
 if(src == inter)
 {
  in = 1;
 }
 if(src == dest && in == 1)
 {
  printpath(path,pathindex);
  printf("\n");
 }
 else
 {
  struct node *crawl = G->array[src].head;
  while(crawl)
  {
   if(visited[crawl->num] != 1)
    printallpathsutil(G,crawl->num,dest,inter,in,visited,path,pathindex);
   crawl = crawl->next;
  }
 }
 visited[src] = 0;
 pathindex--;
}   
  
void printallpaths(struct graph *G,int src,int dest,int inter)
{
 int visited[G->vertices];
 int path[G->vertices];
 int i,pathindex = -1;
 for(i=0;i< G->vertices ; i++)
  visited[i] = 0;
 
 printallpathsutil(G,src,dest,inter,0,visited,path,pathindex);
} 

void main()
{
 struct graph *G = creategraph(5);
 
 addedge(G,0,1);
 addedge(G,2,1);
 addedge(G,2,3);
 addedge(G,4,3);
 addedge(G,0,4);
 addedge(G,1,4);
 addedge(G,1,3);
 
 printallpaths(G,1,3,0);
 
}
 
