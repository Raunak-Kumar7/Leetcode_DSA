// pivot chosen at the each step divides the array into roughly equal halves.
// Best case time complexity of quicksort is O(n log n).

// Worst Case:  when the pivot at each step consistently results in highly unbalanced partitions.
//  O(n^2).
//  When the array is already sorted and the pivot is always chosen as the smallest or largest element.

// Merge sort is more efficient and works faster than quick sort in case of larger array size or datasets.
// whereas Quick sort is more efficient and works faster than merge sort in case of smaller array size or datasets.

//(In-place - stack space O(N)
// Not Stable

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}