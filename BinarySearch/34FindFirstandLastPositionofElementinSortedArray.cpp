    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int result=-1;
        vector<int> ans;
        while(start<=end) //firstposition
        {
            int mid = (start+end)/2;
            if(nums[mid]==target)
            {
                result=mid;
                end=mid-1;
                
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
                end=mid-1;
        }
        ans.push_back(result);
        start=0;
        end=nums.size()-1;
        result=-1;
        while(start<=end) //lastposition
        {
            int mid = (start+end)/2;
            if(nums[mid]==target)
            {
                result=mid;
                start=mid+1;
                
            }
            else if(nums[mid]<target)
            {
                start=mid+1;
            }
            else
                end=mid-1;
        }
        ans.push_back(result);
        return ans;
        
        
    }


//To find number of elements (Also put a check, calculate number only if element exists, i.e. pos!=-1)
//last position-firstposition+1