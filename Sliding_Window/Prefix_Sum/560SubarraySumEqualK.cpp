    //as the array can contain negative numbers also we can not use the slidign window approach 
    //therefore we use the hashmap approach as in pepcoding
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //stores prefix sum, frequency
        int count = 0;
        int sum = 0;
        mp[0]=1;//Important insert{0,1}
        for(auto it: nums)
        {
            sum+=it;
            count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }