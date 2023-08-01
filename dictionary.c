/*Write a program to implement dictionary for the following operations : insert ,delete,search
Created on : 18-7-23
Author: Lasya Nalagandla, 22251A3656
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define size 11
struct data
{
 int key;
 int value;
 bool nused;
};
void insert(int,int);
int hashfunc(int);
int search(int);
void display();
int delete(int);
struct data ht[size];
int hashfunc(int key)
{
 return (key%size);
};
void main()
{
 int key,value,s,d,ele,e;
 int ch;
 for(int i=0;i<size;i++)
 {
 ht[i].key=-1;
 ht[i].value=-1;
 ht[i].nused=true;
 }
 do
 {
 printf("1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
 printf("Enter a choice");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1 : printf("Enter key and value : \n");
 scanf("%d%d",&key,&value);
 insert(key,value);
 break;
 case 2 : printf("Enter the key that needs to be deleted\n");
 scanf("%d",&ele);
 d=delete(ele);
 printf("Deleted key %d is at pos : %d \n",ele,d);
 break;
 case 3 : printf("Element that needs to be searched ");
 scanf("%d",&e);
 s=search(e);
 if(s==-1)
 printf("Element not found\n");
 else
 printf("Element found at pos :%d\n",s);
 break;
 case 4 : display();
 break;
 case 5 : exit(0);
 break;
 default : printf("Invalid choice\n");
 }
 }while(1);
}
void insert(int k,int v)
{
 int hashindex,i;
 hashindex=hashfunc(k);
 i=hashindex;
 while(ht[i].key!=-1)
 {
 i=(i+1)%size;
 if(i==hashindex)
 {
 printf("Hashtable is full\n");
 return;
 }
 }
 ht[i].key=k;
 ht[i].value=v;
 ht[i].nused=false;
}
int search(int k)
{
 int i,hashindex;
 hashindex=hashfunc(k);
 i=hashindex;
 while(ht[i].nused!=true)
 {
 if(ht[i].key==k)
 return i;
 i=(i+1)%size;
 if(i==hashindex)
 {
 break;
 }
 }
 return -1;
}
int delete (int k)
{
 int s;
 s=search(k);
 if(s!=-1)
 {
 ht[s].key=-1;
 ht[s].value=-1;
 }
 return s;
}
void display()
{
 int i;
 for(i=0;i<size;i++)
 printf("key : %d value : %d\n",ht[i].key,ht[i].value);
}
/*output
student@student:~/22251A3656$ gcc dictionary.c
student@student:~/22251A3656$ ./a.out
test case 1: INSERT
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
23 55
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
89 5
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice4
key : -1 value : -1
key : 23 value : 55
key : 89 value : 5
key : -1 value : -1
key : -1 value : -1
key : -1 value : -1
key : -1 value : -1
key : -1 value : -1
key : -1 value : -1
key : -1 value : -1
key : -1 value : -1
test case 2: insertion -hashtable full
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
2 78
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
7 44
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
34 9
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
87 4
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
6 4
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
77 4
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
55 9
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
90 8
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
3 88
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
99 46
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
22 6
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice1
Enter key and value :
5 80
Hashtable is full
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice4
key : 77 value : 4
key : 34 value : 9
key : 2 value : 78
key : 55 value : 9
key : 90 value : 8
key : 3 value : 88
key : 6 value : 4
key : 7 value : 44
key : 99 value : 46
key : 22 value : 6
key : 87 value : 4
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice
test case 3: DELETE
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice2
Enter the key that needs to be deleted
89
Deleted key 89 is at pos : 2
test case 4 : SEARCH
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice3
Element that needs to be searched 23
Element found at pos :1
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice3
Element that needs to be searched 89
Element not found
test case 5: delete and search on empty hashtable
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice2
Enter the key that needs to be deleted
23
Deleted key 23 is at pos : -1
1.Insert
2.Delete
3.Search
4.Display
5.Exit
Enter a choice3
Element that needs to be searched 23
Element not found
1.Insert
2.Delete
3.Search
4.Display
5.Exit
*/ 
