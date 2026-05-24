#include<stdio.h>
#define MAX 10
int D[MAX][MAX], n;

void war()
{
    int i, j, k;
    for(k = 1; k <= n; k++)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                D[i][j] = D[i][j] || (D[i][k] && D[k][j]);
            }
        }
    }
}

int main()
{
    int i, j, k;
    printf("Enter the nummber of vertices : ");
    scanf("%d", &n);
    printf("Enter the Adjacency Matrix \n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &D[i][j]);
        }
    }
    war();
    printf("The Transitive Closure Matrix are \n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%d \t", D[i][j]);
        }
        printf("\n");
    }
}