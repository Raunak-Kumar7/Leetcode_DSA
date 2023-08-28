// T.C. - O(N^2)
// S.C. - O(1)
// works by repeatedly swapping the adjacent elements if they are in the wrong order.

// In this way, the largest element is moved to the rightmost end at first.
// This process is then continued to find the second largest and place it and so on until the data is sorted.

// DRY RUN:
// Iteration1: largest element to last
//  [6, 0, 3, 5]
//  [0, 6, 3, 5]
//  [0, 3, 6, 5]
//  [0, 3, 5, 6]

// Ascending order
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++) // can also be n-i
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Optimised
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1; j++) // can also be n-i
        {
            if (a[j] > a[j + 1])
            {
                flag = true;
                swap(a[j], a[j + 1]);
            }
        }
        if (!flag)
            break;
    }
}

// stable?
// Yes,

// Q) Does sorting happen in place in Bubble sort?
// Yes

// Bubble sort takes minimum time (Order of n) when elements are already sorted. Hence it is best to check if the array is already sorted or not beforehand, to avoid O(N2) time complexity.
