//Stack 
    //if a previous car has lesser time to reach destination than the car ahead it --> it will join it 
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //sort based on distnace
        //Can also use pq to sort the pairs
        vector<pair<int,int>> v;
        int n = position.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({position[i],speed[i]});
        }
        sort(v.begin(),v.end());
        vector<double> time;
        for(int i=0;i<n;i++)
        {
            time.push_back(1.0*(target-v[i].first)/v[i].second);
        }
        stack<double> st;
        int fleet = 0;
        double maxi;
        for(int i=n-1;i>=0;i--)
        {
            if(!st.empty() && maxi>=time[i])
            {
                maxi = max(maxi,time[i]);
            }
            else
            {
                if(!st.empty()) st.pop();
                fleet++;
                st.push(time[i]);
                maxi = time[i];
            }
        }
        return fleet;
    }