//2nd Program
#include<stdio.h>
#define INFI 999
#define MAX_VERTICES 10
int wt[MAX_VERTICES][MAX_VERTICES];
int edges[MAX_VERTICES - 1][2];
int mincost = 0;
int n;
void prims(int source);
int main()
{
    int i, j, source;
    printf("Enter the Number of Vertices : ");
    scanf("%d", &n);
    printf("Enter the Cost Matrix : \n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &wt[i][j]);
        }
    }
    printf("Enter the source Vertex form (1 to %d) : ", n);
    scanf("%d", &source);
    if(source < 1 || source > n)
    {
        printf("Invalid Source Vertex please enter the Valid Source Vertex from (1 to %d)", n);
        return 1;
    }
    prims(source);
    return 0;
}

void prims(int source)
{
    int visited[MAX_VERTICES] = {0};
    int lowcost[MAX_VERTICES];
    int u[MAX_VERTICES];
    int i, j, v, min;
    visited[source] = 1;
    for(i = 1; i <= n; i++)
    {
        if(i != source)
        {
            lowcost[i] = wt[source][i];
            u[i] = source;
        }
    }
    for(i = 1; i <= n-1; i++)
    {
        min = INFI;
        v = -1;
        for(j = 1; j <= n; j++)
        {
            if(visited[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                v = j;
            }
        }
        if(v == -1)
        {
            printf("The Graph Cannot be Constructed. MST cannot be formed");
            return;
        }
        edges[i - 1][0] = u[v];
        edges[i - 1][1] = v;
        mincost += lowcost[v];
        visited[v] = 1;
        lowcost[v] = INFI;
        for(j = 1; j <= n; j++)
        {
            if(visited[j] == 0 && wt[v][j] < lowcost[j])
            {
                lowcost[j] = wt[v][j];
                u[j] = v;
            }
        }
    }
    printf("edge of minimum cost spanning Tree are \n");
    for(i = 0; i< n - 1; i++)
    {
        printf("(%d, %d )\n", edges[i][0], edges[i][1]);
    }
    printf("The minimum cost spanning Tree Weight is %d", mincost);
}