int robber(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0) // if we are standing at 0 means we did not pick 1--> so we should pick 0 to maximise
        return nums[0];
    if (n < 0)
        return 0;
    if (dp[n] != -1) // Step3
        return dp[n];
    int left = nums[n] + robber(nums, n - 2, dp); // Pick //edge case if n==1 ---> n-2 will give negative index
    int right = 0 + robber(nums, n - 1, dp);      // Not Pick
    return dp[n] = max(left, right);              // Step2
}
int rob(vector<int> &nums)
{
    // Question is same as House robber 1
    // Onlly change is that first and last houses are also connected -->circular
    // so it means we can not take first and last house together
    // so first apply house robber excluding first then once excluding last --> take maximum
    // for all approaches look house robber 1

    int n = nums.size();
    // Edge Case
    if (n == 1)
        return nums[0];
    vector<int> dp(n - 1, -1);
    vector<int> dp2(n - 1, -1);
    vector<int> nums1; // Find Better method instead of creating new arrays
    vector<int> nums2;
    for (int i = 1; i < n; i++)
        nums1.push_back(nums[i]);
    for (int i = 0; i < n - 1; i++)
        nums2.push_back(nums[i]);
    return max(robber(nums1, n - 2, dp), robber(nums2, n - 2, dp2));
}

// Cleaner code

int f(int i, int last, vector<int> &nums, vector<int> &dp)
{
    if (i < last)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int pick = nums[i] + f(i - 2, last, nums, dp);
    int notPick = f(i - 1, last, nums, dp);

    return dp[i] = max(pick, notPick);
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp(n, -1);
    vector<int> dp2(n, -1);
    return max(f(n - 1, 1, nums, dp), f(n - 2, 0, nums, dp2));
}