//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
//The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]

//https://leetcode.com/problems/combination-sum/

void func(int index, int target,vector<int>& candidates,vector<vector<int>>& ans, vector<int>& temp, int n)
    {
        if(index == n)
        {
            if(target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[index]<=target)
        {
            temp.push_back(candidates[index]);
            func(index,target-candidates[index],candidates,ans,temp,n);
            temp.pop_back();
        }
        func(index+1,target,candidates,ans,temp,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n  = candidates.size();
        vector<int> temp;
        func(0,target,candidates,ans,temp,n);
        return ans;
    }