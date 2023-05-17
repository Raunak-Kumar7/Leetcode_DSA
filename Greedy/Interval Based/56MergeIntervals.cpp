    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end()); //sort by start time
        vector<vector<int>> ans;
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int i= 1;i<n;i++)
        {
            if(intervals[i][0] <= end)
            {
                end = max(end,intervals[i][1]); // keep including in same interval till intersecting
                //update end by maximum of all ends in this interval
            }
            else
            {
                ans.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }