    //Sort by Density(price/wt) in decreaing order
    static bool comp(pair<double,int> a, pair<double,int> b)
    {
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> p; //{density,index}
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            p.push_back({1.0*arr[i].value/arr[i].weight,i});
        }
        sort(p.begin(),p.end(),comp);
        for(int i=0;i<n;i++)
        {
            if(W>0)
            {
                int wt = min(W,arr[p[i].second].weight);
                ans += wt*p[i].first;
                W-=wt;
            }
            else 
                break;
        }
        return ans;
    }