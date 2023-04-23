//Longest Subarray of size K(Variable Sized Sliding Window --> ONLY FOR NON NEGATIVE)

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
        int n = a.size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        long long sum = 0; 
        while(j<n) //3 conditions
        {
            sum+=a[j];
            if(sum<k)
            {
                j++;
            }
            else if(sum==k)
            {
                maxi = max(maxi,j-i+1);
                //dont remove here, bcz might encounter a 0
                j++;
            }
            else if(sum>k)
            {
                while(sum>k) //decrease TILL greater than K
                {
                    sum-=a[i];
                    i++;
                }
                //on decreasing it might become =k
                if(sum==k)
                {
                    maxi = max(maxi,j-i+1);
                }
                j++;
            }
        }
        return maxi;
}