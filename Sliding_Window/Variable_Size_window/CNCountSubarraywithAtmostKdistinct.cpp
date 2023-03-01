//related to 992
int kDistinctSubarrays(vector<int> &nums, int n, int k)
{
    // Write your code here
    //Sliding Window Variable sized
    int i=0,j=0;
    int ans = 0;
    unordered_map<int,int> mp;
    int count = 0;
    while(j<n)
    {
        mp[nums[j]]++;
        count = mp.size();
        if(count<=k)
        {
            ans+=j-i+1;
            j++; 
        }
        else if(count>k)
        {
            while(count>k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                    count--;
                }
                i++;
            }
            ans+=j-i+1;
            j++;
        }
    }
    return ans;
}