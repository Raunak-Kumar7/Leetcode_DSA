
//https://leetcode.com/problems/subsets/

//similar to subset sum1 on gfg

//Brute Force is Power set solution TC (2^n x n)
    void solve(int ind,vector<int>& nums, vector<vector<int>>& ans,vector<int>& temp,int n)
    {
        if(ind==n)
        {
            ans.push_back(temp);
            return;
        }
        //take
            temp.push_back(nums[ind]);
            solve(ind+1,nums,ans,temp,n);
            temp.pop_back();
        //not take
            solve(ind+1,nums,ans,temp,n);
      
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        solve(0,nums,ans,temp,n);
        return ans;
    }