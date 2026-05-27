#include<stdio.h>
int set[10], x[10], d, n;
void sumofsub(int, int);
int main()
{
    int sum = 0, i;
    printf("Enter the number of subsets : ");
    scanf("%d", &n);
    printf("Enter the Elements in the subsets : ");
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the maximum Limit of the subset : ");
    scanf("%d", &d);
    printf("The sum of the subset are ");
    for(i = 1; i <= n; i++)
    {
        sum = sum + set[i];
    }
    if(sum < d || set[1] > d)
    {
        printf("No subsets are possible");
    }
    else
    {
        sumofsub(0, 1);

    }
    return 0;
}

void sumofsub(int s, int k)
{
    int i;
    x[k] = 1;
    if(s + set[k] == d)
    {
        printf("{");
        for(i = 1; i <= k; i++)
        {
            if(x[i] == 1)
            {
                printf("%d", set[i]);
            }
        }
        printf("}\n");
    }
    else if(s + set[k] < d && k < n)
        sumofsub(s + set[k], k + 1);
    if(s + set[k] <= d && k < n)
    {
        x[k] = 0;
        sumofsub(s, k+1);
    }
}