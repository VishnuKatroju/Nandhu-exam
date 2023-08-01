/*Write a program to implement binary search using recursion
Created on : 13-6-23
Author: Lasya Nalagandla, 22251A3656
*/
#include<stdio.h>
#include<stdlib.h>
void binarysearch(int ar[],int high,int low,int ele);
void main()
{
int n,ele;
printf("Enter number of elements in an array : ");
scanf("%d",&n);
int a[n];
printf("Enter elements: ");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("Enter element to search : ");
scanf("%d",&ele);
for(int i=0;i<n;i++)
{
for(int j=0;j<n-1;j++)
{
if(a[j]>a[j+1])
{
int temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
}
for(int k=0;k<n;k++)
printf("a[%d] = %d\n",k,a[k]);
binarysearch(a,n-1,0,ele);
}
void binarysearch(int ar[],int high,int low,int ele)
{
int mid=(low+high)/2;
if(low>high)
{
printf("Not Found:(\n");
return;
}
else if(ar[mid]==ele)
{
printf("Found at position %d!!\n",mid);
return;
}
else
{
if(ar[mid]>ele)
binarysearch(ar,mid-1,low,ele);
else
binarysearch(ar,high,mid+1,ele);
}
}
/*OUTPUTS:
student@user:~/22251a3661$ gcc binaryrec.c
student@user:~/22251a3661$ ./a.out
Enter number of elements in an array : 5
Enter elements: 2
1
54
34
56
Enter element to search : 4
a[0] = 1
a[1] = 2
a[2] = 34
a[3] = 54
a[4] = 56
Not Found:(
student@user:~/22251a3661$ ./a.out
Enter number of elements in an array : 5
Enter elements: 34
678
23
67
12
Enter element to search : 12
a[0] = 12
a[1] = 23
a[2] = 34
a[3] = 67
a[4] = 678
Found at position 0!!
*/
