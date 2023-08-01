/*Write a C program to implement selection sort
Created on : 27-6-23
Author: Lasya Nalagandla, 22251A3656
*/
#include<stdio.h>
void selectionsort(int [],int);
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
 selectionsort(a,n);
 printf("Elements after sorting: \n");
 for(i=0;i<n;i++)
 printf("a[%d] : %d \n",i,a[i]);
}
void selectionsort(int a[],int n)
{
 int pos,i,t,j;
 for(i=0;i<n-1;i++)
 {
 pos=i;
 for(j=i+1;j<n;j++)
 {
 if(a[j]<a[pos])
 pos=j;
 }
 if(i!=pos)
 {
 t=a[i];
 a[i]=a[pos];
 a[pos]=t;
 }
 }
}
/*output
student@student:~/22251A3656$ gcc selectionsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 5
Before sorting the elements are:
a[0] : 45
a[1] : 90
a[2] : 87
a[3] : 66
a[4] : 2
Elements after sorting:
a[0] : 2
a[1] : 45
a[2] : 66
a[3] : 87
a[4] : 90
student@student:~/22251A3656$ gcc selectionsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 4
Before sorting the elements are:
a[0] : 34
a[1] : 45
a[2] : 69
a[3] : 98
Elements after sorting:
a[0] : 34
a[1] : 45
a[2] : 69
a[3] : 98
student@student:~/22251A3656$ gcc selectionsort.c
student@student:~/22251A3656$ ./a.out
Enter no. of elements : 3
Before sorting the elements are:
a[0] : 98
a[1] : 55
a[2] : 34
Elements after sorting:
a[0] : 34
a[1] : 55
a[2] : 98
*/
