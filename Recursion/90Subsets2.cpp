

//brute force solve like subset 1 by pick and non pick technique, after that store all subsets in a set//extra space 2^n * log(2^n)
    //optimised approach is picking up in a subsequence 
    void solve(int ind,vector<int>& nums, vector<vector<int>>& ans,vector<int>& temp,int n)
    {
        ans.push_back(temp);
        for(int i=ind;i<n;i++)
        {
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solve(i+1,nums,ans,temp,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        sort(nums.begin(),nums.end());//to bring all same numbers together
        solve(0,nums,ans,temp,n);
        return ans;
    }