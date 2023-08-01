/*Write a C program to implement insertion sort
Created on : 27-6-23
Author: Lasya Nalagandla, 22251A3656*/
#include<stdio.h>
void insertionsort(int [],int);
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
 insertionsort(a,n);
 printf("Elements after sorting: \n");
 for(i=0;i<n;i++)
 printf("a[%d] : %d \n",i,a[i]);
}
void insertionsort(int a[],int n)
{
 int p,t,i;
 for(i=1;i<n;i++)
 {
 t=a[i];
 p=i-1;
 while(t<a[p] && p>=0)
 {
 a[p+1]=a[p];
 p=p-1;
 }
 a[p+1]=t;
 }
}
/*output
student@student:~/22251A3656$ gcc insertsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 5
Before sorting the elements are:
a[0] : 33
a[1] : 98
a[2] : 45
a[3] : 2
a[4] : 12
Elements after sorting:
a[0] : 2
a[1] : 12
a[2] : 33
a[3] : 45
a[4] : 98
student@student:~/22251A3656$ gcc insertsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 3
Before sorting the elements are:
a[0] : 32
a[1] : 55
a[2] : 79
Elements after sorting:
a[0] : 32
a[1] : 55
a[2] : 79
student@student:~/22251A3656$ gcc insertsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 3
Before sorting the elements are:
a[0] : 88
a[1] : 77
a[2] : 44
Elements after sorting:
a[0] : 44
a[1] : 77
a[2] : 88
*/
