//Given an array of integers nums and an integer target, return //indices// of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

//Because we need indices sorting is not a good option, though we can solve by storing indices
//Brute Force O(n^2)

    vector<int> twoSum(vector<int>& nums, int target) {
        //sort(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(i==j)
                    continue;
        
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            
            }
    }
}


//O(n) T.C 
//O(n) S.C.
vector<int> twoSum(vector<int>& nums, int target) {
        //optimised solution
        unordered_map<int,int> mp;  //value,index
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            auto it = mp.find(target-nums[i]);  
            if(it!=mp.end())
            {
                if(i == it->second)   //you may not use the same element twice
                    continue;
                ans.push_back(i);
                ans.push_back(it->second);
                break;
            }
        }
        return ans;
    }