#include<stdio.h>
#include<stdlib.h>

struct node
{
 int num;
 int weight;
 struct node *next;
};

struct adjlist
{
 struct adjlist *head;
};

struct graph
{
 int vertices;
 struct adjlist *array;
};

struct graph *creategraph(int vertices)
{
 struct graph *G = (struct graph*)malloc(sizeof(struct graph));
 G->vertices = vertices;
 G->array = (struct adjlist*)malloc(vertices * sizeof(struct adjlist));
 int i;
 for(i=0;i<vertices;i++)
  G->array[i].head = NULL;
 return G;
}

struct node *createnode(int num,int weight)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 ptr->num = num;
 ptr->weight = weight;
 ptr->next = NULL;
 return ptr;
}
 
void addedge(struct graph *G,int src,int dest,int weight)
{
 struct node *ptr = createnode(dest,weight);
 ptr->next = G->array[src].head;
 G->array[src].head = ptr;
 
 struct node *ptr1 = createnode(src,weight);
 ptr->next = G->array[dest].head;
 G->array[dest].head = ptr;
}

struct minheapnode
{
 int v;
 int key; 
};

struct minheap
{
 int size;                                  // Number of nodes present currently in min heap
 int capacity;                              // Capacity of min heap
 int *pos;
 struct minheapnode **array;
}

struct minheapnode *newminheapnode(int v,int key)
{
 struct minheapnode *mn = (struct minheapnode*)malloc(sizeof(struct minheapnode));
 mn->v = v;
 mn->key = key;
 return mn;
}

struct minheap *createminheap(int v)
{
 struct minheap *m = (struct minheap*)malloc(sizeof(struct minheap));
 m->size = 0;
 m->capacity = v;
 m->pos = (struct int*)malloc(v * sizeof(struct int));
 m->array = (struct minheapnode**)malloc(sizeof(struct minheapnode*));
 return m;
}

void swap(struct minheapnode **a,struct minheapnode **b)
{
 struct minheapnode *t = *a;
 *a = *b;
 *b = *t;
} 

void heapify(struct minheap *m,int idx)
{
 int smallest,left,right;
 smallest = idx;
 left = 2*idx + 1;
 right = 2*idx + 2;
 if(m->array[smallest]->key > m->array[left]->key)
 {
  smallest = left;
 }
 if(m->array[smallest]->key > m->array[right]->key)
 {
  smallest = right;
 }
 
 if(smallest != idx)
 {  
  m->pos[m->array[smallest]->v] = idx;
  m->pos[m->array[idx]->v] = smallest;
 
  swap(&m->array[idx],&m->array[smallest]);
  heapify(m,smallest);
 } 
}

struct minheapnode *extractmin(struct minheap *m)
{
 if(size == 0)
  return NULL;
 struct minheapnode *ptr = m->array[0];
 swap(&m->array[0],&m->array[size-1]);
 
 m->pos[m->array[0]->v] = 0;
 
 --m->size;
 
 heapify(m,0);
 return ptr;
}
  
void decreasekey(struct minheap *m,int v,int key)
{
 int idx = m->pos[v];
 m->array[idx]->v = v;
 m->array[idx]->key = key;
 int parent = (idx-1)/2;
 while(parent >= 0 && (&m->array[parent]->key > m->array[idx]->key))
 {
   int i = m->pos[m->array[parent]->v];
   m->pos[m->array[parent]->v] = m->pos[array[idx]->v];
   m->pos[array[idx]->v] = i;
   
   swap(&m->array[idx],&m->array[parent]);
  
   idx = parent;
   parent = (idx-1)/2;
 }
}   
  
int isinminheap(struct minheap *m,int v)
{
 int idx = m->pos[v];
 if(m->array[idx] == 0)
  return 0;
 else
  return 1;
}

void printarr(int A[],int n)
{
 int i;
 for(i=0;i<n;i++)
  printf("%d - %d",A[i],i);
}   

void primMST(struct graph *G)
{
 
 int display[G->vertices];
 struct minheap *m = createminheap(G->vertices);
 int i,idx;
 for(i=1;i< G->vertices ;i++)
 {
  m->pos[i] = i;
  m->array[i] = newminheapnode(i,2147483647);
  display[i] = -1;
 }
 
 display[0] = -1;
 m->pos[0] = 0;                                                    
 m->array[0] = newminheapnode(0,0);
 
 m->size = G->vertices;
 
 while(m->size != 0)
 {
  struct minheapnode *mn = extractmin(m);
  int u = mn->v;                                                  // Destination vertex number : in result, 0 - 1
                                                                                        //                  |   |
  struct node *crawl = G->array[u].head;                                               //                   v   u
                                                              
  while(crawl)
  {
   idx = m->pos[crawl->num];
   if(isinminheap(m,v) && (crawl->weight < m->array[idx]->key))
   {
     display[v] = u;                                            //  Choosing edge with least weight    
     decreasekey(m,v,crawl->weight);  
   }
   crawl = crawl->next;
  }
 }
 printarr(display,G->vertices);
}

void main()
{
 int V = 9;
 struct graph *G = creategraph(V);
 addEdge(G, 0, 1, 4);
 addEdge(G, 0, 7, 8);
 addEdge(G, 1, 2, 8);
 addEdge(G, 1, 7, 11);
 addEdge(G, 2, 3, 7);
 addEdge(G, 2, 8, 2);
 addEdge(G, 2, 5, 4);
 addEdge(G, 3, 4, 9);
 addEdge(G, 3, 5, 14);
 addEdge(G, 4, 5, 10);
 addEdge(G, 5, 6, 2);
 addEdge(G, 6, 7, 1);
 addEdge(G, 6, 8, 6);
 addEdge(G, 7, 8, 7);
 
 primMST(G);
 
}  
 
   

