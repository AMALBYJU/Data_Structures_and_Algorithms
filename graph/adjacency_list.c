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
 struct graph* G = (struct graph*)malloc(sizeof(struct graph));
 G->array = (struct adjlist*)malloc(v*sizeof(struct adjlist));
 G->vertices = v;
 int i;
 for(i = 0;i<v;i++)
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
 
 ptr = createnode(src);
 ptr->next = G->array[dest].head;
 G->array[dest].head = ptr;
}

void printgraph(struct graph *G)
{
 int i;
 struct node *crawl;
 for(i = 0;i< G->vertices;i++)
 {
  crawl = G->array[i].head;
  printf("\nAdjacency list of vertex %d\n",i);
  while(crawl)
  {
    printf("%d->",crawl->num);
    crawl = crawl->next;
  }
 }
}

void main()
{
 int vertices,edges,start,end,i;
 printf("Enter number of vertices ");
 scanf("%d",&vertices);
 struct graph* G = creategraph(vertices);
 printf("Enter number of edges  in graph ");
 scanf("%d",&edges);
 printf("Enter the edges\n");
 for(i = 0;i<edges;i++)
 {
     printf("Enter starting vertex of edge %d ",i);
     scanf("%d",&start);
     printf("Enter ending vertex of edge %d ",i);
     scanf("%d",&end);	
     addedge(G,start,end);
 }    
 printgraph(G);
}
   
     
