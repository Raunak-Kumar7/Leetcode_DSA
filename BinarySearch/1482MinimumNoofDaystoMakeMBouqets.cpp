//We have minimize so lets take l =1
#define ll long long 
    bool isValid(int mid, vector<int>& bloomDay, int m, int k)
    {
        //We are at day mid we need to check if we can make m bouquets of subarray size k
        int count = 0;
        //we have to check continous subarray of k 
        int siz = 0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid)
            {
                siz++; //increase size till we get a number smaller than mid
            }
            else
            {
                count+= siz/k; //number of subarrays found
                siz = 0;
            }

        }
        count+=siz/k;
        return count>=m;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((ll)m*k>n) return -1; 
        int l = 1; 
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        while(l<r)
        {
            int mid = l + (r-l)/2;
            if(isValid(mid,bloomDay,m,k))
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