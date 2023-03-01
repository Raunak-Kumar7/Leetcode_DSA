vector <int> nearlySorted(int arr[], int n, int K){
        // Your code here
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<=K;i++)
        {
            pq.push(arr[i]);
        }
        int idx = K+1;
        int i = 0;
        while(!pq.empty())
        {
            arr[i] = pq.top();
            pq.pop();
            i++;
            if(idx<n)
            {
                pq.push(arr[idx]);
                idx++;
            }
        }
        //Solved inplace 
        vector<int> ans; //just to return vector 
        for(int i=0;i<n;i++)
            ans.push_back(arr[i]);
        return ans;
    }