    //Approach 1: Brute Force --> map Or traverse array as it is sorted
    //Approach 2: Xor O(n)
    //map and xor also work on non sorted
    
    //Approach 3 : Binary Search O(logn)
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        //All elemnets exist in pair 1,1
        //Before the single element --> (first element of pair always exist on even index 0,2,4 and second at odd index 1,3,5)
        //After the single element -->(first element of pair always exist on odd index 1,3,5 and second at even index 0,2,4))
        
        //If the mid is even --> check mid and mid+1 if both are same means element exist on right
        //If the mid is odd --> check mid and mid-1 if both are same means element exist on right
        
        while(low<high)
        {
            int mid = (low+high)/2;
            if(mid%2==0)
            {
                if(nums[mid]==nums[mid+1])
                {
                    low = mid+2; //if they match pair is made, ans cant be mid or mid+1 bcz pair
                }
                else
                {
                    high = mid; // if they dont match mid can also be our candidate
                }
            }
            else
            {
                if(nums[mid]==nums[mid-1])
                {
                    low = mid+1;// if they match pair is made at correct posiiton so answer on right
                }
                else
                {
                    high = mid;//
                }
            }
        }
        return nums[low];
    }