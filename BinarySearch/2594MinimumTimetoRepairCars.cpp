//Binary Search 
    //Max time -- if mechanic with min rank repairs all the cars
    //min time -- lets take 1
    
    bool isValid(ll mid ,vector<int>& ranks, int cars)
    {
        //check if its possible to wash all the cars in s minutes
        int n = ranks.size();
        ll carwashed = 0;
        for(int i=0;i<n;i++)
        {
            carwashed+=sqrt(mid/ranks[i]);
        }
        return (carwashed>=cars);
    }
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        ll s = 1;
        ll e = (ll)(*min_element(ranks.begin(),ranks.end())) *cars*cars;
        while(s<e)
        {
            ll mid = s+(e-s)/2;
            if(isValid(mid,ranks,cars)) //minimize
            {
                e = mid;
            } 
            else
            {
                s = mid+1;
            }
        }
        return e;
    }