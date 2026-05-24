#include<stdio.h>
#define MAX 10
void top(int ad[MAX][MAX], int n)
{
    int i, j;
    int in_degree[MAX] = {0};
    int torder[MAX];
    int count = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(ad[j][i] != 0)
            {
                in_degree[i]++;
            }
        }
    }
    int flag = 1;
    while(count < n && flag)
    {
        flag = 0;
        for(i = 0; i < n; i++)
        {
            if(in_degree[i] == 0)
            {
                torder[count++] = i;
                in_degree[i] = -1;
                flag = 1;
                for(j = 0; j <= n; j++)
                {
                    if(ad[i][j] != 0)
                    {
                        in_degree[j]--;
                    }
                }
            }
        }
    }
    if(count < n)
    {
        printf("No Topological Order");
    }
    else
    {
        printf("The Topological Sequence \n");
        for(i = 0; i < count; i++)
        {
            printf("%d \t", torder[i] + 1);
        }
        printf("\n");
    }
}

int main()
{
    int ad[MAX][MAX], i, j, n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Enter the matrix of the diagraph \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &ad[i][j]);
        }
    }
    top(ad, n);
    return 0;
}