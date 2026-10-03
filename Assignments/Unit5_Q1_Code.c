/*
A network of n locations is represented as a graph. Write a C program that accepts
the graph using an Adjacency Matrix, accepts a starting vertex, performs a graph
traversal, displays the visit order, and ensures that a vertex is not processed
repeatedly. Test it with connected and partially connected graphs.
*/
#include <stdio.h>
#define MAX 20
int graph[MAX][MAX];
int visited[MAX];
int n;
void DFS(int v)
{
    int i;
    visited[v]=1;
    printf("%d ",v);
    for(i=0;i<n;i++)
    {
        if(graph[v][i]==1&&visited[i]==0)
            DFS(i);
    }
}
void BFS(int start)
{
    int queue[MAX],front=0,rear=0;
    int visitedBFS[MAX]={0};
    int v,i;
    queue[rear++]=start;
    visitedBFS[start]=1;
    while(front<rear)
    {
        v=queue[front++];
        printf("%d ",v);
        for(i=0;i<n;i++)
        {
            if(graph[v][i]==1&&visitedBFS[i]==0)
            {
                queue[rear++]=i;
                visitedBFS[i]=1;
            }
        }
    }
}
int main()
{
    int i,j,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    printf("Enter starting vertex (0 to %d): ",n-1);
    scanf("%d",&start);
    printf("DFS traversal: ");
    for(i=0;i<n;i++)
        visited[i]=0;
    DFS(start);
    printf("\nBFS traversal: ");
    BFS(start);
    printf("\n");
    return 0;
}
