/* Write a program to implement linear search using functions
Created on : 13-6-23
Author: Lasya Nalagandla, 22251A3656
*/
#include<stdio.h>
#define MAX 5
void search(int arr[],int key);
void main()
{
 int key,i,a[MAX];
 for(i=0;i<MAX;i++)
 {
 printf("enter element : ");
 scanf("%d",&a[i]);
 }
 printf("item that needs to be searched\n");
 scanf("%d",&key);
 search(a,key);
}
void search(int arr[],int key)
{
 for(int i=0;i<MAX;i++)
 {
 if(arr[i]==key)
 {
 printf("item found at position %d\n",i);
 return;
 }
 }
 printf("item not found\n");
}
/*output
student@student:~/22251A3656$ gcc ls.c
student@student:~/22251A3656$ ./a.out
enter element : 1
enter element : 2
enter element : 3
enter element : 4
enter element : 5
item that needs to be searched 7
item not found
student@student:~/22251A3656$ gcc ls.c
student@student:~/22251A3656$ ./a.out
enter element : 2
enter element : 3
enter element : 4
enter element : 6
enter element : 8
item that needs to be searched 8
item found at position 5 */
