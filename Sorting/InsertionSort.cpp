// T.C. O(N^2)
// S.C. O(1)

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];

        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// worst case
// Insertion sort takes the maximum time to sort if elements are sorted in reverse order.

// best case
// already sorted

// inplace?
// Yes

// Stable?
//  Yes