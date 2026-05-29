#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000000
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int partition(int a[], int l, int r)
{
    int p = a[l];
    int i = l - 1;
    int j = r + 1;
    while(1)
    {
        do 
        {
            i++;
        } while(a[i] < p);
        do 
        {
            j--;
        } while(a[j] > p);
        if(i >= j) 
            return j;
        swap(a, i, j);
    }
}

void qs(int a[], int l, int r)
{
    if(l < r)
    {
        int s = partition(a, l, r);
        qs(a, l, s);
        qs(a, s + 1, r);
    }
    
}

void input(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }
    printf("The Unsorted array is \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    int *a = (int*)malloc(n * sizeof(int)); //int a[MAX];
    srand(time(0));
    input(a, n);
    clock_t start = clock();
    qs(a, 0, n - 1);
    clock_t end = clock();
    printf("The sorted order are ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    double ElapsedTime = (double)(end - start) / CLOCKS_PER_SEC*1000;
    printf("The Time = %.20f nanoseconds", ElapsedTime);
    free(a);
    return 0;
}