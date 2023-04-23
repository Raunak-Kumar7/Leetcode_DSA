//Fixed Sliding Window
    long maximumSumSubarray(int k, vector<int> &a , int n){
        int i=0;
        int j=0;
        long sum = 0;
        long maxi = 0;
        while(j<n)
        {
            sum+=a[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                maxi = max(maxi,sum);
                sum-=a[i];
                i++;
                j++;
            }
        }
        return maxi;
    }