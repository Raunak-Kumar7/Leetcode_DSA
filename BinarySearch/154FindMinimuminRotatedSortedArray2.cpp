// may Contains duplicates

    
    // [1,2,1,1,1,1,1,1] --> 2
    // [1,1,2,1,1]  --> 3
    // [2,2,1,2,2]  --> 2
    // [2,1,2,2,2,2,2,2,2]  --> 1
    // [1,1,1,1,2,1,1] --> 0 //Incorrect for these cases

    int findMin(vector<int>& nums) {
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
            //Case 3: in case mid and end are same --> decrement end until they are not same Because the first idx of an element is left most so decrement hi and not incremnet mid
            else 
                end--; //WC O(n)
        }
        cout<<start<<endl;
        return nums[start];
    }


        // [1,2,1,1,1,1,1,1] --> 2
    // [1,1,2,1,1]  --> 3
    // [2,2,1,2,2]  --> 2
    // [2,1,2,2,2,2,2,2,2]  --> 1
    // [1,1,1,1,2,1,1] --> 5  //correct
    
    //Code also returns corrects first index of min element (i.e. number of times array is rotated)
    int findMin(vector<int>& nums) {
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
                    cout<<end;
                    return nums[end];
                }
        }
        cout<<start<<endl;
        return nums[start];
    }