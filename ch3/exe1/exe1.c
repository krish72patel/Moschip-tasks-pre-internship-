/*Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and measure
the difference in run-time. */


#include <stdio.h>
int binsearch(int x, int v[], int n);

int main()
{
    // Array must be sorted for binary search
    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 38;
    int n = 10; // Number of elements in the array
    int index;
    index = binsearch(target,array, n);
    printf("binsearch result: index %d\n", index);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    
    while (low <= high) 
	{
        mid = low+(high - low) / 2; 
        if (x <= v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (high + 1 < n && v[high + 1] == x) {
        return high + 1;
    }
    return -1;
}
