
//Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

//Each number in candidates may only be used once in the combination.

//Note: The solution set must not contain duplicate combinations.

//https://leetcode.com/problems/combination-sum-ii/



//Brute Force like Combination Sum 1--> High TC
    void func(int index, int target,vector<int>& candidates,set<vector<int>>& ans, vector<int>& temp, int n)
    {
        if(index == n)
        {
            if(target == 0)
            {
                ans.insert(temp);
            }
            return;
        }
        if(candidates[index]<=target)
        {
            temp.push_back(candidates[index]);
            func(index+1,target-candidates[index],candidates,ans,temp,n); //+1 because we want to use only once each number
            temp.pop_back();
        }
        func(index+1,target,candidates,ans,temp,n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;  //using set to handle duplicates in ans, eg.[[1,2,2],[1,2,2],[1,2,2],[5]]
        int n  = candidates.size();
        vector<int> temp;
        // #### again tranfer all values from set to a 2d vector ,before returning
        func(0,target,candidates,ans,temp,n);
        return ans;
    }


//Optimised Approach // picking subsequences after sorting array
void func(int index, int target,vector<int>& candidates,vector<vector<int>>& ans, vector<int>& temp, int n)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++)
        {
            if(i>index && candidates[i-1]==candidates[i]) continue;  //dont pick same value
            if(candidates[i]>target) //sorted so wont find any further //saves time
                break;
            // if(candidates[i]<=target )//&& i>index && candidates[i-1]!=candidates[i])
            // {
                temp.push_back(candidates[i]);
                func(i+1,target-candidates[i],candidates,ans,temp,n);  //its i+1
                temp.pop_back();
            //}
        }
    }
    //in this approach we are picking subsequences,
    //in the previous ques Q39 we were doing pick or not pick approach
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  //using set to handle duplicates in ans, eg.[[1,2,2],[1,2,2],[1,2,2],[5]]
        int n  = candidates.size();
        vector<int> temp;
        sort(candidates.begin(),candidates.end()); // sorting is important because we are picking subsequences
        func(0,target,candidates,ans,temp,n);
        return ans;
    }
