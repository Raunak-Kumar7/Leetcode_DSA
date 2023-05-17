#define mod 1000000007
    //Constraints dont allow DP
    //We can sort the array as we are not concerned with the subsequence itself but only the minimum and maximum
    //For Every Anchor on left we find the right limit --> and by pick and non pick concept 2^(j-i) - 1 subsequences possible with each anchor
    //only move ahead the anchor, no need to change the right limit. becuase it will only increase the sum(which the earlier (smaller) anchor could not afford)
    //check notes
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        //add single element subsequences
        for(auto it:nums)
        {
            if(2*it<=target)
                ans++;
        }
        //seen the power array --> to precompute power of 2 Else getting RTE
        vector<int> power(n);
        power[0] = 1;
        for(int i=1;i<n;i++)
        {
            power[i] = (2*power[i-1])%mod;
        }
        //2 pointer
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if(nums[i]+nums[j]<=target)//found a pair that satisfies --> make all subseq with these 2 as min and max
            {
                ans += power[j-i] - 1; //elements in bw may be in subseq or may not be        
                ans = ans%mod;
                i++;
            }
            else if(nums[i]+nums[j]>target)
            {
                j--;
            }
        }
        return ans%mod; //take mod at every step
        
    }