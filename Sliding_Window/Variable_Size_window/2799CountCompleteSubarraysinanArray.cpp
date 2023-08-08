// Count subarrays with k distinct numbers questions
int atmostk(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0;
    unordered_map<int, int> mp;
    int count = mp.size();
    int ans = 0;
    while (j < n)
    {
        mp[nums[j]]++;
        count = mp.size();
        if (count <= k)
        {
            ans += j - i + 1;
            j++;
        }
        else if (count > k) // shrink
        {

            while (count > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                    count--;
                }

                i++;
            }
            ans += j - i + 1;
            j++;
        }
    }
    return ans;
}
int countCompleteSubarrays(vector<int> &nums)
{
    unordered_set<int> st;
    for (auto it : nums)
        st.insert(it);
    int k = st.size();

    return atmostk(nums, k) - atmostk(nums, k - 1);
}