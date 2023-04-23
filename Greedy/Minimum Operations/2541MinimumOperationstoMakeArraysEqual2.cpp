//if net diff of entire array is 0 --> means it is possible to convert else not
    //each diff i.e. abs(nums[i]-nums2[i])%k should be ==0 else not possible
    //ans will be sum of either all positive differences(/k) or all negative differences /k
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        if(k==0)
        {
            for(int i=0;i<n;i++)
            {
                if(nums1[i]!=nums2[i]) {return -1;}
            }
            return 0;
        }
        long long diffnet = 0;
        long long operations = 0;
        for(int i=0;i<n;i++)
        {
            int diff = 0;
            diff = nums1[i]-nums2[i];
            if(((int)abs(diff))%k!=0) return -1; //difference should always be a multiple of k, only then it can be adjusted
            diffnet += diff/k;
            if(diff>0) operations += diff/k;
        }
        if(diffnet!=0) return -1; //either nums1 or nums2 have imbalance of greater/smaller values
        return operations;
    }