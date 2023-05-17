// https://youtu.be/BTObFnHbD4U

//here equal end points are considered as non overlapping 
    // 3 case
    // Case 1: No overlap --> dont remove any
    // Case 2: Overlap from the left side i.e. [1-5] , [2-6] --> better to remove [2-6]
    // Case 3: Overlap involing right edge i.e. [1-5],[2-3] or --> better to remove [1-5] larger remove
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1;i<n;i++)
        {
            //either first interval will partially/equally engulf second
            //or it engulfs beyond
            //OR no overlap
            if(end <= intervals[i][0])//no overlap
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
            //partially or equally engulf --> delete the second interval(which may go further and clash with others)
            else if(end > intervals[i][0] && end <= intervals[i][1])
            {
                ans++;
                // no change in start and end
            }
            //engufs beyond --> delete the bigger(first) interval
            else if(end>intervals[i][1])
            {
                ans++;
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        return ans;
        
    }