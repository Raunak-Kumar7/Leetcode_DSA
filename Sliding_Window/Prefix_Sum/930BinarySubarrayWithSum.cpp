    //Brute Force -- generate all subarrays and check sum O(n^2) O(1)
    
    //M2 : Hashmap Approach + Prefix Sum --> General for any array(not 0,1) O(n) O(n)
    
    //understand
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //Prefix Sum Approach LC 560
        unordered_map<int,int> mp; //we dont need indices, we only need count of indices
        int sum = 0;
        int count = 0;
        mp[0]=1; //IMPORTANT
        for(auto i:nums)
        {
            sum+=i;
            count+=mp[sum-goal];
            mp[sum]++;
        }
        return count;
    }


    //M3: Optimised Sliding Window  O(n) O(1)
    //Variable Size window (involving Count)
    //Count of Subarrays with sum K
    