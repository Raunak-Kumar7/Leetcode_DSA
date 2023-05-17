//LC1191
    //Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        //All Negative Case handled Separately
        int neg = 0;
        for(auto i: nums)
        {
            if(i<0) neg++;
        }
        if(neg==n) return *max_element(nums.begin(),nums.end());
        
        int maxsum = 0;
        int currsum = 0;
        for(auto i:nums)
        {
            currsum+=i;
            maxsum = max(maxsum,currsum);
            if(currsum < 0)  //if sum till now is < 0 then better dont take it;
                currsum = 0;
        }
        return maxsum;
    }