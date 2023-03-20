//Binary Search
    //We have to minimize
    //Maximum capacity if all packages delivered in 1 day -> sum of all weights
    //minimum capacity should be the maximum weight present in all 
    bool isValid(int mid, vector<int>& weights, int days)
    {
        int n = weights.size();
        //mid is the capcaity of 1 day, we need to check if with this capacity we can ship in D days  //// packages are to be shipped in Order
        int day = 0;
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(sum+weights[i]<=mid)
            {
                sum+=weights[i];
            }
            else
            {
                day++;
                sum = weights[i];
            }
        }
        if(sum>0) day++;
        
        return day<=days;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(isValid(mid,weights,days))
            {
                r = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        return r;
    }