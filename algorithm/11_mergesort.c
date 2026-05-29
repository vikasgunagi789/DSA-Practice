#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define MAX_SIZE 1000000

void Merge(int B[], int p, int C[], int q, int A[]) { 
    int i = 0, j = 0, k = 0; 

    while (i < p && j < q) { 
        if (B[i] <= C[j]) { 
            A[k++] = B[i++]; 
        } else { 
            A[k++] = C[j++]; 
        } 
    }  

    while (i < p) { 
        A[k++] = B[i++]; 
    } 

    while (j < q) { 
        A[k++] = C[j++]; 
    } 
} 

void Mergesort(int A[], int n) { 
    if (n > 1) { 
        int mid = n / 2; 
        int p = mid; 
        int q = n - mid; 

        int B[p], C[q]; 

        for (int i = 0; i < p; i++) { 
            B[i] = A[i]; 
        } 

        for (int i = 0; i < q; i++) { 
            C[i] = A[mid + i]; 
        } 

        Mergesort(B, p); 
        Mergesort(C, q); 

        Merge(B, p, C, q, A); 
    } 
} 

void input(int a[], int n) { 
    for (int i = 0; i < n; i++) { 
        a[i] = rand() % 1000; 
    } 

    printf("Unsorted array:\n"); 

    for (int i = 0; i < n; i++) { 
        printf("%d ", a[i]); 
    } 

    printf("\n"); 
} 

int main() { 
    int n; 

    printf("Enter the number of elements:\n"); 
    scanf("%d", &n); 

    if (n > MAX_SIZE) { 
        printf("Error: Number of elements exceeds maximum size of %d\n", MAX_SIZE); 
        return 1; 
    } 

    int *a = (int*)malloc(n * sizeof(int)); //int a[MAX_SIZE]; 

    srand(time(NULL)); 

    input(a, n); 

    clock_t start = clock(); 

    Mergesort(a, n); 

    clock_t end = clock(); 

    printf("\nSorted array:\n"); 

    for (int i = 0; i < n; i++) { 
        printf("%d ", a[i]); 
    } 

    printf("\n"); 

    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC * 1000000000; 

    printf("Total time = %f nanoseconds\n", elapsedTime); 
    free(a);
    return 0; 
}