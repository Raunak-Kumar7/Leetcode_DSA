    //Also works for MAX SUM SUBARRAY OF SIZE k
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0;
        int j=0;
        double avg=-DBL_MAX;
        double sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if((sum/k)>avg)
                    avg=sum/k;
                sum=sum-nums[i];
                i++;
                j++;
            }
        }
        return avg;
    }