    //2 questions in 1
    //1) maximum sum of subarray of size k
    //2) subarrays of size k with all distinct elements (MAP)
    #define ll long long
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        ll maxi = 0;
        ll sum = 0;
        unordered_map<int,int> mp;
        while(j<n)
        {
            sum+=nums[j];//1
            mp[nums[j]]++;//2
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(mp.size()==k)//k unique elements only then update maxi
                {
                    maxi = max(maxi,sum);   
                }
                sum-=nums[i];//1
                mp[nums[i]]--;
                if(mp[nums[i]]==0) //so that count is correct
                    mp.erase(nums[i]);
                i++;
                j++;
            }
        }
        return maxi;
    }