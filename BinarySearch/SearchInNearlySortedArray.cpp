//Not found any practice platform
//Approach 1: Brute Force Linear Search

//Approach 2: Binary Search
int search(vector<int>& nums, int target)
{
    int n = nums.size();
    int lo = 0, hi=n-1;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(nums[mid]==target)
            return mid;
        else if(mid+1<n && nums[mid+1]==target)
            return mid+1;
        else if(mid-1>=0 && nums[mid-1]==target)
            return mid-1;
        else if(nums[mid]>target)
            hi = mid-1;
        else
            lo = mid+1;
    }
    return -1;
}