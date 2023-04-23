//Binary Search
    bool isValid(vector<int>& houses, vector<int>& heaters, int radius)
    {
        int n = houses.size();
        int m = heaters.size();
        int r = 0;
        int idx = 0;
        int i = 0;
        while(i<n && idx<m)
        {
            if(abs(houses[i]-heaters[idx])<=radius)
                i++;
            else
                idx++;
        }
        return (i==n);
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int f = 0;
        int l = 1e9;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        while(f<l)
        {
            int mid = (f+l)/2;
            if(isValid(houses,heaters,mid)) //minimise radius
            {
                l = mid;
            }
            else
            {
                f = mid+1;
            }
        }
        return l;
    }