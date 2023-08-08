// SOlN 1: using Stl nth_element
//      int findKthLargest(vector<int>& nums, int k)
//     {
//  	    nth_element(nums.begin(),nums.begin()+nums.size()-k,nums.end());
//  	    return nums[nums.size()-k];
//     }
//  int findKthLargest(vector<int>& nums, int k)
//     {
//  	    nth_element(nums.begin(),nums.begin()+k-1,nums.end(),greater<int>());
//  	    return nums[k-1];
//     }

// SOlN 1: using Stl partial_sort
//  int findKthLargest(vector<int>& nums, int k)
//  {
//  partial_sort(nums.begin(),nums.begin()+nums.size()-k+1,nums.end());
//  return nums[nums.size()-k];
//  }
//  int findKthLargest(vector<int>& nums, int k)
//  {
//  partial_sort(nums.begin(),nums.begin()+k,nums.end(),greater<int>());
//  return nums[k-1];
//  }

// ----------------------------------
// Soln 3: Multiset
// Soln 4: Maxheap

// Soln 5: Quick Select --> read abt it

// Soln 6: Min Heap

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : nums)
    {
        pq.push(it);
        if (pq.size() > k)
            pq.pop();
    }
    return pq.top();
}