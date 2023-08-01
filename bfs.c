/* Write a program to implement breadth first search traversal of the graph
Created on : 22-7-23
Author: Lasya Nalagandla, 22251A3656*/
*/
#include <stdio.h>
int q[20];
int rear=-1,front=-1,n;
void insert(int ele)
{
 q[++rear]=ele;
 if (front==-1)
 front=0;
}
int del()
{
 if(front==-1 || front>rear)
 return(-1);
 else
 return(q[front++]);
}
void bfs(int adj[][20],int visited[],int start);
void bfs(int adj[][20],int visited[],int start)
{
 int i;
 insert(start);
 visited[start]=1;
 while(front<=rear)
 {
 start = del();
 printf("%d\n",start);
 for(i=0;i<n;i++)
 {
 if(adj[start][i] && !visited[i])
 {
 insert(i);
 visited[i]=1;
 }
 }
 }
}
void main ()
{
 int visited[20] = { 0 }, adj[20][20]={0}, i, j, v1, v2, type, start;
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
 bfs(adj,visited,start);
}
/*OUTPUTS:
Enter no of vertices:3
Enter directed(0) or undirected(1)
1
enter the edge(source to desti.to stop -1 -1)0 1
enter the edge(source to desti.to stop -1 -1)0 2
enter the edge(source to desti.to stop -1 -1)1 2
enter the edge(source to desti.to stop -1 -1)-1 -1
adj matrix is
0 1 1
1 0 1
1 1 0
Enter the starting vertex:0
0
1
2
Enter no of vertices:10
Enter directed(0) or undirected(1)0
enter the edge(source to desti.to stop -1 -1)0 1
enter the edge(source to desti.to stop -1 -1)0 2
enter the edge(source to desti.to stop -1 -1)0 3
enter the edge(source to desti.to stop -1 -1)
1 4
enter the edge(source to desti.to stop -1 -1)2 4
enter the edge(source to desti.to stop -1 -1)3 2
enter the edge(source to desti.to stop -1 -1)3 5
enter the edge(source to desti.to stop -1 -1)3 6
enter the edge(source to desti.to stop -1 -1)4 7
enter the edge(source to desti.to stop -1 -1)5 2
enter the edge(source to desti.to stop -1 -1)5 7
enter the edge(source to desti.to stop -1 -1)6 7
enter the edge(source to desti.to stop -1 -1)6 8
enter the edge(source to desti.to stop -1 -1)9 8
enter the edge(source to desti.to stop -1 -1)9 7
enter the edge(source to desti.to stop -1 -1)-1 -1
adj matrix is
0 1 1 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 1 0 0 1 1 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0
Enter the starting vertex:0
0
1
2
3
4
5
6
7
8
*/
