/**
 * exercise 2-4: design and implement an algorithm that will sort an
 * array of n integers as slow as possible. 
 * 
 * I didn't come up with slowsort. 
 * wikipedia page: https://en.wikipedia.org/wiki/Slowsort
 * 
 * "...even the best case is worse than bubblesort."
 * */

#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void slow_sort(int *n, int start, int last)
{
    int mid;
    if (start < last) {
        mid = (start + last)/2;
        slow_sort(n, start, mid);       // sort first half recursively
        slow_sort(n, mid + 1, last);    // sort the second half recursively
        
        if (n[mid] > n[last])
                swap(&n[mid], &n[last]);
        slow_sort(n, start, last - 1);
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
    int a[] = {2, 6, 23, 4, 9, 6, 8, 7, 0};
    int len = sizeof(a)/sizeof(*a);
    slow_sort(a, 0, len-1);
    print_arr(a, len);
}