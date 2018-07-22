#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
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

struct graph *creategraph(int v)
{
 struct graph *G = (struct graph*)malloc(sizeof(struct graph));
 G->vertices = v;
 G->array = (struct adjlist*)malloc(G->vertices * sizeof(struct adjlist));
 int i;
 for(i=0;i< G->vertices;i++)
  G->array[i].head = NULL;
 return G;
}

struct node *createnode(int v,int weight)
{
 struct node *ptr = (struct node*)malloc(sizeof(struct node));
 ptr->num = v;
 ptr->weight = weight;
 ptr->next = NULL;
 return ptr;
} 

void addEdge(struct graph *G,int src,int dest,int weight)
{
 struct node *ptr = createnode(dest,weight);
 ptr->next = G->array[src].head;
 G->array[src].head = ptr;
 
 ptr = createnode(src,weight);
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
 int size;
 int capacity;
 int *pos;
 struct minheapnode **array;
};

struct minheap *createminheap(int vertices)
{
 struct minheap *m = (struct minheap*)malloc(sizeof(struct minheap));
 m->size = 0;
 m->capacity = vertices;
 m->pos = (int*)malloc(vertices * sizeof(int));
 m->array = (struct minheapnode**)malloc(vertices * sizeof(struct minheapnode*));
 return m;
}

struct minheapnode *createminheapnode(int v,int key)
{
 struct minheapnode *ptr = (struct minheapnode*)malloc(sizeof(struct minheapnode));
 ptr->v = v;
 ptr->key = key;
 return ptr;
}

void swap(struct minheapnode **a,struct minheapnode **b)
{
 struct minheapnode *t = *a;
 *a = *b;
 *b = t;
}

void heapify(struct minheap *m,int idx)
{
 int smallest,left,right;
 smallest = idx;
 left = 2*idx + 1;
 right = 2*idx + 2;
 
 if((m->array[smallest]->key > m->array[left]->key) && m->size > left) 
  smallest = left;
 if((m->array[smallest]->key > m->array[right]->key) && m->size > right)
  smallest = right;
  
 if(idx != smallest)
 {
  int t = m->pos[m->array[smallest]->v];
  m->pos[m->array[smallest]->v] = m->pos[m->array[idx]->v];
  m->pos[m->array[idx]->v] = t;
  
  swap(&m->array[smallest],&m->array[idx]);
  heapify(m,smallest);
 }  
}

struct minheapnode *extractmin(struct minheap *m)
{
 if(m->size == 0)
  return NULL;
 struct minheapnode *ptr = m->array[0];
 int t = m->pos[m->array[0]->v];
 m->pos[m->array[0]->v] = m->pos[m->array[m->size-1]->v];
 m->pos[m->array[m->size-1]->v] = t;
 
 swap(&m->array[0],&m->array[m->size-1]);

 --m->size;
 heapify(m,0); 
 return ptr;
}

void decreasekey(struct minheap *m,int v,int key)
{
 int idx = m->pos[v];
 m->array[idx]->key = key;
 
 while((m->array[idx]->key < m->array[(idx-1)/2]->key) && ((idx-1)/2 >= 0))
 {
  int t = m->pos[m->array[idx]->v];
  m->pos[m->array[idx]->v] = m->pos[m->array[(idx-1)/2]->v];
  m->pos[m->array[(idx-1)/2]->v] = t;
  
  swap(&m->array[idx],&m->array[(idx-1)/2]);
  
  idx = (idx-1)/2;
 }
} 
int isinminheap(struct minheap *m,int v)
{
 int i;
 for(i=0;i< m->size;i++)
 {
  if(m->array[i]->v == v)
   return 1;
 }
 return 0;
}

void printarr(int A[],int n)
{
 int i;
 for(i=0;i<n;i++)
  printf("%d-%d\n",A[i],i);
}

void dijkstra(struct graph *G,int src)
{
 struct minheap *m = createminheap(G->vertices);
 m->size = G->vertices;
 m->capacity = G->vertices;
 int dist[G->vertices];
 int display[G->vertices];
 int i;
 for(i=0;i< G->vertices;i++)
 {
  m->pos[i] = i;
  m->array[i] = createminheapnode(i,INT_MAX);
  dist[i] = INT_MAX;
 }
 
 m->array[src]->key = 0 ;
 dist[src] = 0;
 decreasekey(m,src,0);
 
 while(m->size != 0)
 {
  struct minheapnode *ptr = extractmin(m);
  int u = ptr->v;
  
  struct node *crawl = G->array[u].head;
  
  while(crawl)
  {
   if(isinminheap(m,crawl->num) && m->array[m->pos[crawl->num]]->key > (dist[u] + crawl->weight))
   {
    dist[crawl->num] = dist[u] + crawl->weight;
    decreasekey(m,crawl->num,dist[u] + crawl->weight);
   }
   crawl = crawl->next;
  }
 }
 
 printarr(dist,G->vertices);
 
}  

int main()
{
    // create the graph given in above fugure
    int V = 9;
    struct graph* G = creategraph(V);
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
 
    dijkstra(G, 0);
 
    return 0;
} 
  

 
