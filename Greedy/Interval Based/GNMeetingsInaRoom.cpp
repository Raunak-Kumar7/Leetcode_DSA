///Exact Same Code for G ACTIVITY SELECTION


int maxMeetings(int start[], int end[], int n)
    {
        //Sort by finishing time --> pick first --> keep picking if no overlap
        
        vector<pair<int,int>> p;  //{finishtime, starttime}
        for(int i=0;i<n;i++)
        {
            p.push_back({end[i],start[i]});
        }
        sort(p.begin(),p.end());
        int ans = 1;
        int endtime = p[0].first;
        for(int i=1;i<n;i++)
        {
            if(p[i].second > endtime)
            {
                ans++;
                endtime = p[i].first;
            }
        }
        return ans;
    }