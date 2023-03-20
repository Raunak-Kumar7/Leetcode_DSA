    //Binary Search approach(return floor of sqrt)
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int ans = 0;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if((1LL)*mid*mid<=x) //satisfies
            {
                ans = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return ans;
    }