// Recursive Approach
int f(int i, int arr[], int n, int k)
{
    if (i == n)
        return -1;

    if (arr[i] == k)
        return i + 1;

    return f(i + 1, arr, n, k);
}
int search(int arr[], int n, int k)
{
    return f(0, arr, n, k);
}