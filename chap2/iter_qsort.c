/**
 * exercise 2-1: quicksort is most naturally expressed recursively. write it
 * iteratively and compare the two versions.
 * 
 * this is way more complicated iteratively than recursively.
 * I wasn't able to get it totally, this solution here is pretty
 * much all copied from: https://www.geeksforgeeks.org/iterative-quick-sort/
 * 
 * 
 * */

#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int l, int h) 
{ 
    int x = arr[h]; 
    int i = (l - 1); 
  
    for (int j = l; j <= h - 1; j++) { 
        if (arr[j] <= x) { 
            i++; 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[h]); 
    return (i + 1); 
} 

void qsort_iter(int arr[], int l, int h) 
{ 

    int stack[h - l + 1]; 
    int top = -1; 
  
    // push initial values of l and h to stack 
    stack[++top] = l; 
    stack[++top] = h; 
  
    // Keep popping from stack while is not empty 
    while (top >= 0) { 
        // Pop h and l 
        h = stack[top--]; 
        l = stack[top--]; 
  
        // Set pivot element at its correct position 
        // in sorted array 
        int p = partition(arr, l, h); 
  
        // If there are elements on left side of pivot, 
        // then push left side to stack 
        if (p - 1 > l) { 
            stack[++top] = l; 
            stack[++top] = p - 1; 
        } 
  
        // If there are elements on right side of pivot, 
        // then push right side to stack 
        if (p + 1 < h) { 
            stack[++top] = p + 1; 
            stack[++top] = h; 
        } 
    } 
} 

void print_arr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
    printf("\n");
} 
  

int main() 
{ 
    int arr[] = { 4, 3, 5, 2, 1, 3, 2, 3 , 67,34,2,4,3,5,9,9,9,8,7,78,78,78,78,76,5,3,567,435,4,3,3333}; 
    int n = sizeof(arr) / sizeof(*arr); 
    qsort_iter(arr, 0, n - 1); 
    print_arr(arr, n); 
    return 0; 
} 