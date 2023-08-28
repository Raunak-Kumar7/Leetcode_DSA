// T.C. - O(N^2)
// S.C. - O(1)

// The algorithm repeatedly selects the smallest (or largest) element
// from the unsorted portion of the list and swaps it with the first element of the unsorted part.

// Dry Run:
// Iteration1:
// [64,25,12,22,11]
// [11,25,12,22,64]
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }
        if (i != minIdx)
            swap(a[i], a[minIdx]);
    }
}

// Stable Selection Sort
// Order of elements remians same
void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIdx])
            {
                minIdx = j;
            }
        }
        int key = a[minIdx];
        for (int k = minIdx; k > i; k--)
        {
            a[k] = a[k - 1];
        }
        a[i] = key;
    }
}

// in-place?
// Yes