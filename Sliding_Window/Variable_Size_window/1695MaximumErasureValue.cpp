//Sliding Window
    //Maximum subarray sum + maximum size of subarray having unique elements
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        long long sum = 0;
        long long maxi = 0;
        while(j<n)
        {
            if(mp.find(nums[j])==mp.end())
            {
                mp[nums[j]]++;
                sum+=nums[j];
                j++;
                maxi = max(maxi,sum);
            }
            else //duplicate element incoming
            {
                while(mp[nums[j]]!=0)
                {
                    mp[nums[i]]--;
                    sum-=nums[i];
                    i++;
                }
                sum+=nums[j];
                mp[nums[j]]++;
                maxi = max(maxi,sum);
                j++;
            }
        }
        
        return maxi;
    }