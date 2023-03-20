//Binary Search 
    //we will get minimum sum when divisor is = max element
    //We have to minimize
    bool isValid(int mid, vector<int>& nums, int threshold)
    {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum+=ceil((double)nums[i]/mid); //without double it will take floor value
        }
        return sum<=threshold;
    }
    //threshold>=n (given)
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(),nums.end());
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(isValid(mid,nums,threshold))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return r;
    }