#include<stdio.h>
int main()
{
    int i, j, max_qty, m, n, choice;
    float sum, max;
    int array[2][20];
    printf("Enter the number of each items : ");
    scanf("%d", &n);
    printf("Enter the weight of the item : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[0][i]);
    }
    printf("Enter the values in the items : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &array[1][i]);
    }
    printf("Enter the maximum weight of the knapsack : ");
    scanf("%d", &max_qty);
    while(1)
    {
        printf("KNAPSACK PROBLEM\n");
        printf("1. Descrete Knapsack \n");
        printf("2. Continous Knapsack \n");
        printf("3. exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice == 3)
        {
            printf("Exiting the program...");
            break;
        }
        sum = 0;
        m = max_qty;
        int value_copy[20];
        for(i = 0; i < n; i++)
        {
            value_copy[i] = array[1][i];
        }
        while(m > 0)
        {
            max = 0;
            j = -1;
            for(i = 0; i < n; i++)
            {
                if(array[0][i] != 0 && value_copy[i] != 0)
                {
                    if((float)value_copy[i]/array[0][i] > max)
                    {
                        max = (float)value_copy[i]/array[0][i];
                        j = i;
                    }
                }
            }
            if(j == -1) break;
            if(choice == 1)
            {
                if(array[0][j] <= m)
                {
                    printf("Item %d added \n", j + 1);
                    m -= array[0][j];
                    sum += value_copy[j];
                }
                value_copy[j] = 0;
            }
            else if(choice == 2)
            {
                if(array[0][j] > m)
                {
                    printf("Fraction of item %d added %d \n", j+1, m);
                    sum += m * max;
                    m = 0;
                }
                else
                {
                    printf("Item %d added \n", j + 1);
                    m -= array[0][j];
                    sum += value_copy[j];
                    value_copy[j] = 0;
                }
            }
            else
            {
                printf("Invalid choice \n");
                break;
            }
        }
        printf("Total profit = %.2f\n", sum);
    }
    return 0;
}