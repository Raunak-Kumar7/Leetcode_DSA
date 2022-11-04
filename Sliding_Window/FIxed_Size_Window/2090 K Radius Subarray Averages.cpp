// Based on sum of subarray of size k

// https://leetcode.com/problems/k-radius-subarray-averages/


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,-1);
        int idx=k; //non -1 will start filling from index k
        
        k=2*k +1;
        int i=0;
        int j=0;
        long sum =0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                double avg = (double)sum/k;
                ans[idx]=avg;
                idx++;
                sum-=nums[i];
                i++;
                j++;
            }
        }
        return ans;
        
    }
};