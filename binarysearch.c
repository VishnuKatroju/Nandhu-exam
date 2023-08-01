/*Write a program to implement binary search using functions
Created on : 13-6-23
Author: Lasya Nalagandla, 22251A3656
*/
#include<stdio.h>
#define MAX 5
void search(int a[],int key);
void main()
{
 int key,j,temp,i,a[MAX];
 for(i=0;i<MAX;i++)
 {
 printf("enter element : ");
 scanf("%d",&a[i]);
 }
 printf("item that needs to be searched\n");
 scanf("%d",&key);
 for(i=0;i<MAX;i++)
 {
 for(j=0;j<MAX-1;j++)
 {
 if(a[j]>a[j+1])
 {
 temp=a[j];
 a[j]=a[j+1];
 a[j+1]=temp;
 }
 }
 }
 printf("After sorting the elements are \n");
 for (i=0;i<MAX;i++)
 printf("a[%d]=%d\n",i,a[i]);
 search(a,key);
}
void search(int a[],int key)
{
 int low,high,mid,flag;
 low=0,high=MAX-1;
 while(low<=high)
 {
 mid=(low+high)/2;
 if(a[mid]==key)
 {
 flag=1;
 break;
 }
 else if(a[mid]<key)
 {
 low=mid+1;
 }
 else if(a[mid]>key)
 {
 high=mid-1;
 }
 }
 if(flag==1)
 printf("%d found at position %d\n",key,mid);
 else
 printf("%d not found\n",key);
}
/*output
student@student:~/22251A3656$ gcc bs.c
student@student:~/22251A3656$ ./a.out
enter element : 1
enter element : 2
enter element : 3
enter element : 4
enter element : 5
item that needs to be searched
4
After sorting the elements are
a[0]=1
a[1]=2
a[2]=3
a[3]=4
a[4]=5
4 found at position 3
student@student:~/22251A3656$ gcc bs.c
student@student:~/22251A3656$ ./a.out
enter element : 2
enter element : 4
enter element : 6
enter element : 8
enter element : 9
item that needs to be searched
1
After sorting the elements are
a[0]=2
a[1]=4
a[2]=6
a[3]=8
a[4]=9
1 not found
*/
