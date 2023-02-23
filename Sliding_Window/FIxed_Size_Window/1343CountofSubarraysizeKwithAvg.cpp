//SAME to 643

int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();
        int count=0;
        int i=0;
        int j=0;
        double sum=0;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if((sum/k)>=threshold)
                    count++;
                sum=sum-nums[i];
                i++;
                j++;
            }
        }
        return count;
    }