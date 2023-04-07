    //Better Approach Using resize(), Order doesnt matter
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it]++;
        vector<vector<int>> ans;
        for(auto it:mp)
        {
            if(it.second>ans.size()) //if number of rows are less than number of duplicate elements , we need more rows
                ans.resize(it.second);
            for(int i=0;i<it.second;i++) //push element in each row till freq
                ans[i].push_back(it.first);
        }
        return ans;
    }