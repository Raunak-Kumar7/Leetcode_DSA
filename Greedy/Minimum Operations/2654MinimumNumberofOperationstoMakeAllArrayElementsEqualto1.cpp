    //could have done in contest if seen the constraints
    
    
    //Case 1: if nums has 1 --> number of operations = no. of non 1s (1 operations for each)
    //Case 2: of gcd of entire nums != 1 --> not possible --> -1
    //Case 3: we want to make atleast 1 1 fastest(with least no of operations)
    // eg. [2,6,3,4] -- gcd(2,3,6) == 1 & gcd(3,4)==1 but 3,4 is faster
    // so basically we need to find smallest subarray with gcd 1
    
    //Constraints are small(50) we check for each subarray 
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(),nums.end(),1);
        if(ones>0)
            return n - ones; //case 1
        //case2
        int minLength = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int hcf = nums[i];
            for(int j=i;j<n;j++)
            {
                hcf = __gcd(hcf,nums[j]);
                if(hcf==1)
                {
                    minLength = min(minLength, j-i+1);
                    break;
                }    
            }
        }
        //case3
        if(minLength == INT_MAX) return -1;
        return (minLength-1) + n-1;
    }