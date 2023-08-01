/*Write a C program to implement quick sort
Created on : 4-7-23
Author: Lasya Nalagandla, 22251A3656*/
#include<stdio.h>
void qsort(int [],int,int);
void swap(int *,int *);
void main()
{
 int n,i,a[20];
 printf("Enter no. of elements : ");
 scanf("%d",&n);
 printf("Before sorting the elements are: \n");
 for(i=0;i<n;i++)
 {
 printf("a[%d] : ",i);
 scanf("%d",&a[i]);
 }
 qsort(a,0,n-1);
 printf("Elements after sorting: \n");
 for(i=0;i<n;i++)
 printf("a[%d] : %d \n",i,a[i]);
}
void qsort(int a[],int left,int right)
{
 int t,l,r,pivot,i;
 l=left;
 r=right;
 if(left<right)
 {
 pivot=a[left];
 while(l<=r)
 {
 while((l<=r)&&a[l]<=pivot) l++;
 while((r>=l)&&a[r]>pivot) r--;
 if(l<r)
 swap(&a[l],&a[r]);
 }
 swap(&a[left],&a[r]);
 qsort(a,left,r-1);
 qsort(a,r+1,right);
 }
}
void swap(int *a,int *b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}
/*
output
student@student:~/22251A3656$ gcc qsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 4
Before sorting the elements are:
a[0] : 23
a[1] : 44
a[2] : 3
a[3] : 7
Elements after sorting:
a[0] : 3
a[1] : 7
a[2] : 23
a[3] : 44
student@student:~/22251A3656$ gcc qsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 4
Before sorting the elements are:
a[0] : 12
a[1] : 13
a[2] : 14
a[3] : 15
Elements after sorting:
a[0] : 12
a[1] : 13
a[2] : 14
a[3] : 15
student@student:~/22251A3656$ gcc qsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 4
Before sorting the elements are:
a[0] : 98
a[1] : 78
a[2] : 68
a[3] : 48
Elements after sorting:
a[0] : 48
a[1] : 68
a[2] : 78
a[3] : 98
*/
