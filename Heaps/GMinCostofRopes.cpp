   #define ll long long
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        //Approach -- keep joining Min 2 because we dont want greater value to be added more times
        priority_queue<ll,vector<ll>, greater<ll> > pq;
        for(int i=0;i<n;i++)
            pq.push(arr[i]);
        ll ans = 0;
        while(pq.size()>1)
        {
            ll x = pq.top();
            pq.pop();
            ll y = pq.top();
            pq.pop();
            ans+=x+y;
            pq.push(x+y);
        }
        return ans;
        
    }