/*Binary Search
Binary search algorithm is a search algorithm that finds the position of a target value within a sorted array in ascending order. It compares the target value to the middle element of the array; if they are unequal, the half in which the target cannot lie is eliminated and the search continues on the remaining half until it is successful. [Problem] Find the given number in a sorted array using binary search algorithm. [Input] The first input line contains the number of test cases, T. The next line contains the number of elements, M (2 ≤ M ≤ 100). The third line contains the number of the numbers to search. Then, the sorted array will be listed. On the next line, the numbers to search will be listed. [Output] For each given test case, print the index number of the given number. If it does not match, print -1. 

Input:
2 // # of test cases T 12 // # of elements in array M 5 // # of numbers to search N 3 7 28 29 43 49 55 58 69 77 79 99 // sorted integer array 8 49 58 44 7 // numbers to search 7 3 3 4 5 6 7 8 9 1 2 3
Output:
#1 -1 5 7 -1 1 #2 -1 -1 0
*/
#include <stdio.h>

#define MAX_M 100

int T;    // # of test case
int M;    // # of element in array
int N;    // # of numbers to search
int arr[MAX_M];

void binarySearch(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high) 
    {
        printf("-1 ");
        return;
    }

    mid = (low + high) / 2;

    if (target < arr[mid])
    {
        binarySearch(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearch(arr, mid + 1, high, target);
    }
    else 
    {
        printf("%d ", mid);
        return;
    }
}

int main(void)
{
    int targetValue;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) 
    {
        printf("#%d ", test_case);
        scanf("%d %d", &M, &N);

        for (int i = 0; i < M; i++)
        {
            scanf("%d", &arr[i]);
        }

        for (int i = 0; i < N; i++) 
        {
            scanf("%d", &targetValue);
            binarySearch(arr, 0, M-1, targetValue);
        }
        printf("\n");
    }
    return 0;
}
