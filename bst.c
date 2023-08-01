/*Write a program to implement binary search tree insertion, search and traverse.
Created on : 25-7-23
Author: Lasya Nalagandla, 22251A3656
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node
{
int data;
struct node *left,*right;
}bstnode;
bstnode* stack[20];
int top=-1,n;
void push(bstnode* r)
{
stack[++top]=r;
}
bstnode* pop()
{
if(top==-1)
return NULL;
 else
return(stack[top--]);
}
bstnode * insert(bstnode*, int);
void preorder(bstnode* );
void inorder(bstnode* );
void postorder(bstnode* );
void inorder_iterative(bstnode*);
int rsearch(bstnode*,int);
bool isempty(bstnode*);
void main()
{
int num,ch,data,s,d;
bstnode *root=NULL;
while(1)
{
 printf("\n1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit");
 printf("\nEnter your choice: ");scanf("%d",&ch);
 switch(ch)
{
 case 1: printf("Enter integer: ");
 scanf("%d",&num);
 root=insert(root,num);
 break;
 case 2: if(isempty(root))
 printf("Tree is empty");
 else
 {
 printf("Preoder:");
 preorder(root);
 }
 break;
 case 3:if(isempty(root))
 printf("Tree is empty");
 else
 {
 printf("inorder:");
 inorder(root);
 }
 break;
 case 4:if(isempty(root))
 printf("Tree is empty");
 else
 {
 printf("Postorder:");
 postorder(root);
 }
break;
 case 5: printf("Enter the element to be searched:");
 scanf("%d",&data);
 s=rsearch(root,data);
 if(s==1) printf("found"); else printf("not found");
 break;
 case 6: if(isempty(root))
 printf("Tree is empty");
 else
 {
 printf("inorder(iterative):");
 inorder_iterative(root);
 }
 break;
 case 7: exit(0);
 default: printf("Wrong choice....\n");
 }
}
}
bool isempty(bstnode *root)
{
 if (root==NULL)
 return true;
 else
 return false;
}
bstnode * insert(bstnode *root, int n)
{
 bstnode *newn;
if(root==NULL)
{
 newn=(bstnode*) malloc (sizeof(bstnode));
 newn->left=newn->right=NULL;
 newn->data=n;
 return(newn);
}
if(n<root->data)
 root->left=insert(root->left,n);
else
 root->right=insert(root->right,n);
return(root);
}
void preorder(bstnode *r)
{
if(r!=NULL)
{
 printf("%d ",r->data);
 preorder(r->left);
 preorder(r->right);
}
}
void inorder(bstnode *r)
{
if(r!=NULL)
{
 inorder(r->left);
 printf("%d ",r->data);
 inorder(r->right);
}
}
void postorder(bstnode *r)
{
if(r!=NULL)
{
 postorder(r->left);
 postorder(r->right);
 printf("%d ",r->data);
}
}
void inorder_iterative(bstnode *r)
{
 while(r!=NULL)
{
 push(r);
 if(r->left!=NULL)
 r=r->left;
 else
 {
 do
 {
 if(top==-1)
 break;
 r=pop();
 printf("%d ",r->data);
 }while(r->right==NULL);
 r=r->right;
 }
}
}
int rsearch(bstnode *r,int n)
{
 if(isempty(r)) return 0;
 else if(n==r->data)
 return 1;
 if(n<r->data)
 return(rsearch(r->left,n));
 else
 return(rsearch(r->right,n));
}
/*Output
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 1
Enter integer: 22
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 1
Enter integer: 65
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 1
Enter integer: 88
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 1
Enter integer: 54
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 1
Enter integer: 90
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 1
Enter integer: 7
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 2
Preoder:22 7 65 54 88 90
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 3
inorder:7 22 54 65 88 90
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 4
Postorder:7 54 90 88 65 22
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 5
Enter the element to be searched:6
not found
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 5
Enter the element to be searched:88
Found
1.Insert 2.Preorder 3.Inorder 4.Postorder 5.search 6.inorderr-iter 7.exit
Enter your choice: 6
inorder(iterative):7 22 54 65 88 90
*/
