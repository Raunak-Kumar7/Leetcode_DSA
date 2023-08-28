T.C.- O(nlogn) S.C.- O(n)

    // Merge Sort WTC O(nlogn) O(n) Space
    void merge(vector<int> &nums, int l1, int mid, int r1)
{
    vector<int> temp;
    int n = nums.size();
    int i = l1;
    int j = mid + 1;
    while (i <= mid && j <= r1)
    {
        if (nums[i] < nums[j])
        {
            temp.push_back(nums[i]);
            i++;
        }
        else
        {
            temp.push_back(nums[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= r1)
    {
        temp.push_back(nums[j]);
        j++;
    }
    int idx = 0;
    for (int i = l1; i <= r1; i++)
    {
        nums[i] = temp[idx++];
    }
}
void mergeSort(vector<int> &nums, int f, int l)
{
    if (f < l) // not have to sort single element so not =
    {
        int mid = (f + l) / 2;
        mergeSort(nums, f, mid); // last index is inclusive
        mergeSort(nums, mid + 1, l);
        merge(nums, f, mid, l);
    }
}
vector<int> sortArray(vector<int> &nums)
{
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return nums;
}

// Not in-place:

// stable
