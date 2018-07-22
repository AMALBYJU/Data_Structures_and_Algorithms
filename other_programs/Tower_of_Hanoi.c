#include<stdio.h>
// This program solves the Tower of Hanoi puzzle.
// This program displays the shortest sequence of moves required for a given number of disks.
// The moves are displayed in this format
// source -> destination
// The number at source denotes the source peg number.
// The number at destination denotes the destination peg number.
// This means that the topmost disk at source peg is moved to destination peg.
// The objective of this game is to move all disks from peg 1 to peg 3.
   
int TOH(int n,int src,int dest)
{
 int m = 6 - src- dest;
 if(n==1)
 {
  printf("%d -> %d\n",src,dest);
  return 0;
 }
 else if(n==2)
 {
  printf("%d -> %d\n%d -> %d\n%d ->%d\n",src,m,src,dest,m,dest);
  return 0;
 }
 else
  return TOH(n-1,src,m) + TOH(1,src,dest) + TOH(n-1,m,dest);
  return 0; 
}
 
void main()
{
 int n;
 printf("Enter number of rings ");
 scanf("%d",&n);
 TOH(n,1,3);
}
 
