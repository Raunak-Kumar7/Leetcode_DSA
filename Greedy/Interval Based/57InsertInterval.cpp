//Approach 1: add all intervals in one array --> apply merge intervals
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }



//Approach 2:
    //Add intervals which dont intersect
    //Merge intersecting
    //Add intervals which do not intersect
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)     {   
        int n = intervals.size();
        int i=0;
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        while(i<n)
        {
            if(intervals[i][1]>=start)
                break;
            else
            {
                ans.push_back(intervals[i]);
                i++;
            }
        }
        //intersecting intervals
        while(i<n)
        {
            if(start>=intervals[i][0] || end >= intervals[i][0])
            {
                start = min(start,intervals[i][0]);
                end = max(end,intervals[i][1]);
                i++;
            }
            else 
                break;
        }
        ans.push_back({start,end});
        //push remaining intervals
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
    }