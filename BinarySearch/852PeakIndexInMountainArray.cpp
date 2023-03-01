    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(mid-1>=0 && arr[mid-1]<arr[mid] && mid+1<n && arr[mid]>arr[mid+1]) //guaranteed to be a mountain array so we always find a peak before reaching either 0 of n-1
                return mid;
            else if(mid-1>=0 && arr[mid]<arr[mid-1]) //eg 1 10 20 19 (18) 17 16 15 14  peak lies where mis match(greater neighbour) is there(i.e. move to higher number till you are highest)
                //2greater neighbour can not exist because guarantee mountain array
                hi = mid-1;
            else
                lo = mid+1;
        }
        return -1;
    }