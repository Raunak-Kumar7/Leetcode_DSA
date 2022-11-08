//Recursive Approach


//Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//optimised solution less space swapping in place

// https://leetcode.com/problems/permutations/

    void func(int index, vector<int>& nums, vector<vector<int>>& ans)
    {
        if(index ==nums.size())
        {
            ans.push_back(nums);
            return ;
        }
        for(int i= index;i<nums.size();i++)
        {
            swap(nums,i,index);
            func(index+1,nums,ans); //here index+1
            swap(nums,i,index);
        }
    }
    void swap(vector<int>& nums, int i,int idx)
    {
        int t = nums[i];
        nums[i] = nums[idx];
        nums[idx] = t;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        func(0,nums,ans);
        return ans;
    }