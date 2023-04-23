    //Observation : +2,-2 allowed  --> even Number remains even & odd number remains odd
    //so solving them separately
    
    //if number of odds in both arrays are diff --> itll never be possible to convert
    // (similar to LC2541)
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        //can be solved without using extra space by 2 pointers
        
        sort(nums.begin(),nums.end());
        sort(target.begin(),target.end());
        vector<int> numsE;
        vector<int> numsO;
        vector<int> tarE;
        vector<int> tarO;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) numsE.push_back(nums[i]);
            else numsO.push_back(nums[i]);
            if(target[i]%2==0) tarE.push_back(target[i]);
            else tarO.push_back(target[i]);
        }
        
        long long netdiff = 0;
        long long operations = 0;
        for(int i=0;i<numsE.size();i++)
        {
            int diff = numsE[i] - tarE[i];
            netdiff += diff/2;
            if(diff > 0) operations+=diff/2;
        }
        for(int i=0;i<numsO.size();i++)
        {
            int diff = numsO[i] - tarO[i];
            netdiff += diff/2;
            if(diff > 0) operations+=diff/2;
        }
        //as given in question it'll always be possible --> netdiff = 0
        return operations;
        
    }