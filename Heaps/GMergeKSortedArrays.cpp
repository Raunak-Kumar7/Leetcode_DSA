vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //min heap {element, {row,index}}
        //min heap sorted by first element
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
        vector<int> ans;
        //all vectors are sorted, inserting smallest element of each vector in min heap
        for(int i=0;i<K;i++) 
        {
            pq.push({arr[i][0],{i,0}});
        }
        while(pq.size()>0)
        {
            int t = pq.top().first;
            ans.push_back(t);
            int r = pq.top().second.first;//r is the vector number
            int c = pq.top().second.second; //c is the current index in the rth vector
            pq.pop();
            if(c<arr[r].size()-1) //vector r not yet exhausted
            {
                pq.push({arr[r][c+1],{r,c+1}});
            }
        }
        return ans;
    }