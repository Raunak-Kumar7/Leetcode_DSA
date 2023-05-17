//Implementation should be using Min heap instead of max heap because we want max frequent
    //T.C. O(nlog(n-k))   S.C O(k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it : nums) //stores frequency of each element
        {
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it : mp)
        {
            pq.push({it.second,it.first});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }   
        return ans;
    }