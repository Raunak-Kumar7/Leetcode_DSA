//Given an array of integers temperatures represents the daily temperatures, 
//return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
//If there is no future day for which this is possible, keep answer[i] == 0 instead.

 //Problem is same as Online Stock Span
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s; //to store temp and indices
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top().first<=temperatures[i])
            {
                s.pop();
            }
            if(!s.empty()) //else it is 0
                ans[i]=s.top().second-i;
            s.push({temperatures[i],i});
        }
        return ans;
    }