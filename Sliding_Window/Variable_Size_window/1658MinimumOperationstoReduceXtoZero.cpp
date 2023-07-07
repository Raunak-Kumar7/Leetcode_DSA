// Hint seen
// Reverse Approach: max subarray size with sum exactly = sum-x
// variable sliding window
#define ll long long
int minOperations(vector<int> &nums, int x)
{
    int n = nums.size();
    int i = 0;
    int j = 0;
    ll acc = accumulate(nums.begin(), nums.end(), 0);
    acc = acc - x;
    cout << acc << endl;
    if (acc < 0)
        return -1;
    else if (acc == 0)
        return n;
    int sz = 0;
    ll sum = 0;
    while (j < n)
    {
        sum += nums[j];
        if (sum < acc)
        {
            j++;
        }
        else if (sum == acc)
        {
            sz = max(sz, j - i + 1);
            // nums[i] >=1 , therefore if we add more elements sum!=acc
            j++;
        }
        else
        {
            while (sum > acc && i <= j)
            {
                sum -= nums[i];
                i++;
            }
            // if by decreasing we might get target
            if (sum == acc)
                sz = max(sz, j - i + 1);
            j++;
        }
    }
    if (sz == 0)
        return -1;
    return n - sz;
}