/*Write a C program to implement merge sort
Created on : 4-7-23
Author: Lasya Nalagandla, 22251A3656*/
#include<stdio.h>
void msort(int [],int,int);
void merge(int [],int ,int ,int);
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
 msort(a,0,n-1);
 printf("Elements after sorting: \n");
 for(i=0;i<n;i++)
 printf("a[%d] : %d \n",i,a[i]);
}
void msort(int a[],int left,int right)
{
 int mid;
 if(left<right)
 {
 mid=(left+right)/2;
 msort(a,left,mid);
 msort(a,mid+1,right);
 merge(a,left,mid,right);
 }
}
void merge(int a[],int l,int m,int r)
{
 int temp[10],k=0,j,i;
 for(i=l,j=m+1;i<=m && j<=r; )
 {
 if(a[i]<=a[j])
 {
 temp[k++]=a[i];
 i++;
 }
 else
 {
 temp[k++]=a[j];
 j++;
 }
 }
 while(i<=m)
 temp[k++]=a[i++];
 while(j<=r)
 temp[k++]=a[j++];
 for(i=0;i<k;i++)
 a[l+i]=temp[i];
}
/*output
student@student:~/22251A3656$ gcc msort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 5
Before sorting the elements are:
a[0] : 2
a[1] : 45
a[2] : 66
a[3] : 73
a[4] : 98
Elements after sorting:
a[0] : 2
a[1] : 45
a[2] : 66
a[3] : 73
a[4] : 98
Enter no. of elements : 5
Before sorting the elements are:
a[0] : 88
a[1] : 77
a[2] : 66
a[3] : 55
a[4] : 44
Elements after sorting:
a[0] : 44
a[1] : 55
a[2] : 66
a[3] : 77
a[4] : 88
Enter no. of elements : 5
Before sorting the elements are:
a[0] : 45
a[1] : 34
a[2] : 77
a[3] : 2
a[4] : 90
Elements after sorting:
a[0] : 2
a[1] : 34
a[2] : 45
a[3] : 77
a[4] : 90
*/ 
