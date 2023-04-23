// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.
// [2,2,2,2,2,2]

// ----- Write all approaches------

///Approach 1: Hashmap


//Approach 2 : sorting





//Best Approach
// Approach 3
//Mark the indices
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int idx = abs(nums[i])-1;
            if(nums[idx]<0)
                return idx+1;
            nums[idx] = -1*nums[idx];
        }
        return -1;
    }