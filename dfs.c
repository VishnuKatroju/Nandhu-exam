/* Write a program to implement depth first search traversal of the graph
Created on : 22-7-23
Author: Lasya Nalagandla, 22251A3656*/
#include<stdio.h>
int top=-1;
int stack[20];
void push(int x);
int pop();
void push(int x)
{
 top=top+1;
 stack[top]=x;
}
int pop()
{
 int d=stack[top];
 top=top-1;
 return d;
}
void dfs(int adj[20][20],int visited[],int start,int n);
void dfs(int adj[20][20],int visited[20],int start,int n)
{
 printf("%d \n",start);
 visited[start]=1;
 for(int i=0;i<n;i++)
 {
 if(adj[start][i]==1&&visited[i]!=1)
 push(i);
 }
 start=pop();
 while(top!=-1)
 {
 if(visited[start]!=1)
 dfs(adj,visited,start,n);
 }
}
void main ()
{
 int visited[20] = { 0 }, adj[20][20]={0}, i, j, v1, v2, type, start,n;
 printf ("Enter no of vertices:");
 scanf ("%d", &n);
 printf ("Enter directed(0) or undirected(1)");
 scanf ("%d", &type);
 do
 {
 printf ("enter the edge(source to desti.to stop -1 -1)");
 scanf ("%d%d", &v1, &v2);
 if (v1 == -1 && v2 == -1)
 break;
 else
 {
 adj[v1][v2] = 1;
 if (type)
 adj[v2][v1] = 1;
 }
 } while (1);
 printf("adj matrix is\n");
 for(i=0;i<n;i++)
 {
 for(j=0;j<n;j++)
 printf("%d ",adj[i][j]);
 printf("\n");
 }
 printf("Enter the starting vertex:");
 scanf("%d",&start);
 dfs(adj,visited,start,n);
}
/*OUTPUTS :
Enter no of vertices:8
Enter directed(0) or undirected(1)1
enter the edge(source to desti.to stop -1 -1)0 1
enter the edge(source to desti.to stop -1 -1)0 2
enter the edge(source to desti.to stop -1 -1)1 3
enter the edge(source to desti.to stop -1 -1)1 4
enter the edge(source to desti.to stop -1 -1)2 5
enter the edge(source to desti.to stop -1 -1)2 6
enter the edge(source to desti.to stop -1 -1)3 7
enter the edge(source to desti.to stop -1 -1)4 7
enter the edge(source to desti.to stop -1 -1)5 7
enter the edge(source to desti.to stop -1 -1)6 7
enter the edge(source to desti.to stop -1 -1)-1 -1
adj matrix is
0 1 1 0 0 0 0 0
1 0 0 1 1 0 0 0
1 0 0 0 0 1 1 0
0 1 0 0 0 0 0 1
0 1 0 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 1 0
Enter the starting vertex:0
0
2
6
7
5
4
1
3
*/
