//Approach 1: Brute Force O(n)
    int searchInsert(vector<int>& nums, int target) {
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]<target)
              continue;
            else
                return i;
        }
        return nums.size();
        
    }

//Approach 2: BS O(logn)

    //Binary Search Approach --> As elements are sorted (Unique too here)
    
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return lo;//if not found lo comes at index where element should lie 
    }