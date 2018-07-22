//Kruskal 's MST
#include<stdio.h>
#include<stdlib.h>

struct edge
{
 int src,dest,weight;
};

struct graph
{
 int vertices;
 int edges;
 struct edge *E;
};

struct graph *creategraph(int v,int e)
{
 struct graph *G = (struct graph*)malloc(sizeof(struct graph));
 G->vertices = v;
 G->edges = e;
 G->E = (struct edge*)malloc(e * sizeof(struct edge));
 return G;
}

int partition(struct edge*,int,int);

void Qsort(struct edge A[],int p,int r)
{
 if(p < r)
 {
  int q = partition(A,p,r);
  Qsort(A,p,q-1);
  Qsort(A,q+1,r);
 }
}

void assign(struct edge *a,struct edge *b)
{
 a->src = b->src;
 a->dest = b->dest;
 a->weight = b->weight;
}

int partition(struct edge A[],int p,int r)
{
 struct edge x;
 assign(&x,&A[r]);
 struct edge t;
 
 int i = p-1;
 int j;
 
 for(j = p;j<r;j++)
 {
  if(x.weight >= A[j].weight)
  {
   assign(&t,&A[j]);
   ++i;
   assign(&A[j],&A[i]);
   assign(&A[i],&t);
  }
 }
 assign(&t,&x);
 assign(&A[r],&A[++i]);
 assign(&A[++i],&t);
 return i;
}

void printarr(struct edge E[],int v)
{
 int i;
 for(i=0;i<v;i++)
 {
  printf("%d - %d\n",E[i].src,E[i].dest);
 }
}  

struct subset
{
 int parent;
 int rank;
};

int Find(struct subset subsets[],int x)
{
 if(subsets[x].parent != x)
  subsets[x].parent = Find(subsets,subsets[x].parent);
  
 return subsets[x].parent;
}

void Union(struct subset subsets[],int x,int y)
{
 int xroot = Find(subsets,x);
 int yroot = Find(subsets,y);
 
 if(subsets[xroot].rank < subsets[yroot].rank)
  subsets[xroot].parent = yroot;
 else if(subsets[xroot].rank > subsets[yroot].rank)
  subsets[yroot].parent = xroot;
 else
 {
  subsets[xroot].parent = yroot;
  subsets[yroot].rank++;
 }
}
 
void kruskalMST(struct graph *G)
{
 struct subset *subsets = (struct subset*)malloc((G->vertices-1) * sizeof(struct subset));
 int i,k = 0;
 struct edge result[G->vertices-1];
 for(i=0;i< G->vertices ; i++)
 {
  subsets[i].parent = i;
  subsets[i].rank = 0;
 }
 
 Qsort(G->E,0,G->vertices - 2);
 
 for(i = 0;i< G->vertices - 1;i++)
 {
  int xroot = Find(subsets,G->E[i].src);
  int yroot = Find(subsets,G->E[i].dest);
  
  if(xroot != yroot)
  {
   Union(subsets,xroot,yroot);   
   result[k++] = G->E[i];
  }
 }
 printarr(result,G->vertices-1);
} 

int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct graph* graph = creategraph(V, E);
 
 
    // add edge 0-1
    graph->E[0].src = 0;
    graph->E[0].dest = 1;
    graph->E[0].weight = 10;
 
    // add edge 0-2
    graph->E[1].src = 0;
    graph->E[1].dest = 2;
    graph->E[1].weight = 6;
 
    // add edge 0-3
    graph->E[2].src = 0;
    graph->E[2].dest = 3;
    graph->E[2].weight = 5;
 
    // add edge 1-3
    graph->E[3].src = 1;
    graph->E[3].dest = 3;
    graph->E[3].weight = 15;
 
    // add edge 2-3
    graph->E[4].src = 2;
    graph->E[4].dest = 3;
    graph->E[4].weight = 4;
 
    kruskalMST(graph);
 
    return 0;
}  
