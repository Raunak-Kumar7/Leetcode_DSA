// Sort Normally O(nlogn)

/////OR/////
void sortColors(vector<int>& nums) {
        int zeros=0;
        int ones=0;
        int twos=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                zeros++;
            else if(nums[i]==1)
                ones++;
            else
                twos++;
        }
        
       int i=0;
        while(zeros--)
        {
            nums[i]=0;
            i++;
        }
        while(ones--)
        {
            nums[i]=1;
            i++;
        }
        while(twos--)
        {
            nums[i]=2;
            i++;
        }
    }