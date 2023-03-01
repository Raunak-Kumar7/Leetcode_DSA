//With Duplicates

    //Using the code of Find minimum element in rotated sorted array 2(with duplicates)(code with correct index)
    int getMin(vector<int>& nums)
    {
        int n = nums.size();
        int start = 0, end = n-1;
        while(start<end)
        {
            int mid = (start+end)/2;
            //Case 1: if mid is bigger than end --> smaller elements lie on right
            if(nums[mid]>nums[end]) 
                start = mid+1;
            //Case 2: if mid is smaller than end --> smaller on left , mid is also a candidate
            else if(nums[mid]<nums[end])
                end = mid;
            //Case 3: in case mid and end are same --> decrement end until they are not same 
            else //WC O(n)
                if (end != 0 && nums[end] >= nums[end-1])
                    end--;
                else
                {
                    return end;
                }
        }
        return start;
    }
    bool BS(vector<int>& a, int target, int start, int end)
    {
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(a[mid]==target)
                return true;
            else if(a[mid]>target)
                end = mid-1;
            else
                start = mid+1;
        } //Does not always return an index(if not present)
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int idx = getMin(nums);
        return (BS(nums,target,0,idx-1)||BS(nums,target,idx,n-1));
    }