    //Best Article -- https://www.enjoyalgorithms.com/blog/minimum-in-sorted-and-rotated-array
    //Question is same as number of times array is rotated(with unique elements)
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start=0,end=n-1;
        while(start<end)
        {
            //Case 1: if first element is smaller than last element of the current subarray we are looking, it means
            //that the subarray is sorted and Minimum element will be the first
            if(nums[start]<nums[end])
                return nums[start];
            //Case 2: if mid element is bigger than last element means ans is in right subarray
            int mid = (start+end)/2;
            if(nums[mid]>nums[end])
                start = mid+1;
            //Case 3: else it lies in left half
            else
                end = mid;   //mid can also be our answer so not mid-1
            
        }
        return nums[start];
    }