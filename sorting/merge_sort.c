#include<stdio.h>
void merge(int [],int,int,int);
void mergesort(int A[],int p,int r)
{
 if(p<r)
 {
  int q = (p+r)/2;
  mergesort(A,p,q);
  mergesort(A,q+1,r);
  merge(A,p,q,r);
 }
}

void merge(int A[],int p,int q,int r)
{
 int s = q-p+1;
 int t = r-q;
 int L[s],R[t];
 int i=0,j=0,k=p;
 for(i=0;i<s;i++)
  L[i] = A[i+p];
 for(j=0;j<t;j++)
  R[j] = A[q+1+j];
 i = 0;
 j = 0;
 while(i<s && j<t)
 {
  if(L[i]<R[j])
   A[k++] = L[i++];
  else
   A[k++] = R[j++];
 }
 while(i<s)
  A[k++] = L[i++];
 while(j<t)
  A[k++] = R[j++];
}

void main()
{
 int A[10],i,n;
 printf("Enter the number of elements to be entered ");
 scanf("%d",&n);
 printf("Enter the elements ");
 for(i=0;i<n;i++)
  scanf("%d",&A[i]);
 mergesort(A,0,n-1);
 printf("\nThe sorted array is\n");
 for(i=0;i<n;i++)
  printf("%d ",A[i]);
}
