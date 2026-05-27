#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 1000000
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void selectionsort(int A[], int n)
{
    for(int i = 0; i < n -1; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }
        swap(A, i, min);
    }
}

void input(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }
    printf("The Unsorted Array \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements to be inserted");
    scanf("%d", &n);
    if(n > MAX_SIZE)
    {
        printf("Error The element are more than %d. So Please eneter the Number of elements within 0 - %d range", MAX_SIZE, MAX_SIZE);
        return 1;
    }
    int *a = (int*)malloc(n * sizeof(int));
    input(a, n);
    clock_t start = clock();
    selectionsort(a, n);
    clock_t end = clock();
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    double elapsedTime =(double)(end-start)/CLOCKS_PER_SEC*1000000000;
    printf("total time = %f nanosecond \n", elapsedTime);
    free(a);
    return 0;
}