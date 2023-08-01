/*Write a program to implement linear search using recursion
Created on : 13-6-23
Author: Lasya Nalagandla, 22251A3656
*/
#include<stdio.h>
int search(int a[],int,int);
int key,i,front=0,found,n,a[50];
void main()
{
 printf("enter the number of elements u want to read\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 printf("enter element : ");
 scanf("%d",&a[i]);
 }
 printf("item that needs to be searched\n");
 scanf("%d",&key);
 found=search(a,front,n);
 if(found>=0)
 printf("element found at position %d\n",found);
 else
 printf("element not found\n");
}
int search(int a[],int front, int n)
{
 if(a[front] == key)
 return front;
 else if(front == n)
 return -1;
 else
 return search(a,front+1,n);
}
/*output
student@student:~/22251A3656$ gcc lsrec.c
student@student:~/22251A3656$ ./a.out
enter the number of elements u want to read
5
enter element : 1
enter element : 2
enter element : 3
enter element : 4
enter element : 5
item that needs to be searched
5
element found at position 4
student@student:~/22251A3656$ gcc lsrec.c
student@student:~/22251A3656$ ./a.out
enter the number of elements u want to read
4
enter element : 23
enter element : 45
enter element : 77
enter element : 44
item that needs to be searched
89
element not found
*/
