/*Write a C program to implement heap sort
Created on : 11-7-23
Author: Lasya Nalagandla, 22251A3656*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int h[50],count=-1;
void insert(int);
int delete();
void swap(int *,int *);
bool isempty();
void main()
{
 int a[10],n,i;
 printf("Before sorting\n");
 printf("Enter number of elements: \n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("a[%d] : ",i);
 scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 insert(a[i]);
 for(i=n-1;i>=0;i--)
 a[i]=delete();
 printf("after sorting\n");
 for(i=0;i<n;i++)
 printf("%d ",a[i]);
}
void insert(int e)
{
 int i,par;
 h[++count]=e;
 i=count;
 //sift up
 while(i>0)
 {
 par=(i-1)/2;
 if(h[i]>h[par])
 {
 swap(&h[i],&h[par]);
 i=par;
 }
 else
 break;
 }
}
bool isempty()
{
 if(count==-1)
 return true;
 else
 return false;
}
int delete()
{
 int d,par,child;
 if(isempty())
 {
 printf("empty\n");
 exit(0);
 }
 d=h[0];
 h[0]=h[count];//replace root with last element
 count--;
 //sift down
 par=0;child=2*par+1;
 while(child<=count)//if child exists
 {
 //find which child is larger
 if((child<count) && (h[child]<h[child+1]))
 child++;
 if(h[par]<h[child])
 {
 swap(&h[par],&h[child]);
 par=child;
 child=2*par+1;
 }
 else
 break;
 }
 return d;
}
void swap(int *a,int *b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
/*output
Before sorting
Enter number of elements: 5
a[0] : 23
a[1] : 1
a[2] : 45
a[3] : 7
a[4] : 90
after sorting
1 7 23 45 90 */
