    //Binary Search Approach
    //Maximum speed -- every index in one hour n>=h (given)
    //Minimum speed --> we have to minimize so lets take 1
    bool isValid(vector<int>& piles, int speed, int h)
    {
        int n = piles.size();
        int time = 0;
        for(int i=0;i<n;i++)
        {
            time+=ceil((double)piles[i]/speed);  //Dont do integer Division (WA)
        }
        return time<=h ;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int f = 1;
        int l = *max_element(piles.begin(),piles.end());
        while(f<l)
        {
            int mid = (f+l)/2;
            if(isValid(piles,mid,h)) //then minimize
            {
                l = mid; // mid is also a valid ans
            }
            else
                f = mid+1;
        }
        return l;
    }