//used same approach as lc40

//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.
// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

//https://leetcode.com/problems/combinations/

// as we need only combiations not permutations we will use the
    // subsequence approach as in Combination sum2, i.e. we will return 
    // ans in sorted order
    void func(int idx,vector<int>& arr, int k, vector<vector<int>>& ans, vector<int>& temp)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<arr.size();i++)
        {
            temp.push_back(arr[i]);
            func(i+1,arr,k,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        for(int i=1;i<=n;i++)
            arr.push_back(i);
        vector<int> temp;
        func(0,arr,k,ans,temp);
        return ans;
    }