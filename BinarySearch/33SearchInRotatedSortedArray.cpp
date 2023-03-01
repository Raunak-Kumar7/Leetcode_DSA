    //Step1: find Index of min i.e. number of times array is rotated
    //Step2: Apply BS in Both parts 
    
    int minIndex(vector<int>& nums)
    {
        int n = nums.size();
        if(n==1) return 0; //to handle single size arrays
        int start = 0, end = n-1;
        while(start<end)
        {
            //Case 1: if any subarray has first less than last
            if(nums[start]<nums[end])
                return start; //return idx not element
            int mid = (start+end)/2;
            if(nums[mid]>nums[end])
                start = mid+1;
            else
                end = mid;
        } //this always returns something
        return start; //just to return int
    }
    
    int BS(vector<int>& a, int target, int start, int end)
    {
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(a[mid]==target)
                return mid;
            else if(a[mid]>target)
                end = mid-1;
            else
                start = mid+1;
        } //Does not always return an index(if not present)
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int idx = minIndex(nums);
        cout<<idx<<endl;
        int n = nums.size();
        return max(BS(nums,target,0,idx-1),BS(nums,target,idx,n-1)); //returning max to ignore -1 if any one returns
    }