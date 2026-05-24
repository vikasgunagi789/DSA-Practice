#include<stdio.h>
#define inf 99
void printpath(int);
void dijk(int);
int Minvertex();
int dist[10], p[10], visit[10];
int wt[10][10], n, edge;
int main()
{
    int i, j, s;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        dist[i] = 0;
        p[i] = 0;
        visit[i] = 0;
    }
    printf("Enter the weight matrix \n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &wt[i][j]);
        }
    }
    printf("Enter the source Matrix : ");
    scanf("%d", &s);
    printf("The Shortest path from source vertex %d is \n", s);
    dijk(s);
    printpath(s);
    return 0;
}
void dijk(int s)
{
    int i, j, step, u;
    for(i = 1; i <= n; i++)
    {
        dist[i] = wt[s][i];
        if(dist[i] == inf)
            p[i] = 0;
        else 
            p[i] = s;
    }
    visit[s] = 1;
    dist[s] = 0;
    for(step = 2; step <= n; step++)
    {
        u = Minvertex();
        visit[u] = 1;
        for(j = 1; j <= n; j++)
        {
            if(dist[u] + wt[u][j] < dist[j] && !visit[j])
            {
                dist[j] = dist[u] + wt[u][j];
                p[j] = u;
            }
        }
    }
}

int Minvertex()
{
    int min = inf;
    int u, i;
    for(i = 1; i <= n; i++)
    {
        if((dist[i] < min) && (visit[i] == 0))
        {
            min = dist[i];
            u = i;
        }
    }
    return u;
}

void printpath(int s)
{
    int i, t;

    for(i = 1; i <= n; i++)
    {
        if(visit[i] == 1 && i != s)
        {
            printf("\nvisit -> %d", i);

            printf("\nLength -> %d", dist[i]);

            printf("\nPath : ");

            t = i;

            while(t != s)
            {
                printf("%d <-- ", t);

                t = p[t];
            }

            printf("%d\n", s);
        }
    }
}