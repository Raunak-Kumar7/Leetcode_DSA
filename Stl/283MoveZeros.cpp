    void moveZeroes(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }
        nums.erase(remove(nums.begin(), nums.end(), 0),nums.end());
        for(int i=0;i<count;i++)
        {
            nums.push_back(0);
        }
    }

void moveZeroes(vector<int>& nums) {
        int zeros = count(nums.begin(),nums.end(),0);
        int idx = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[idx] = nums[i];
                idx++;
            }
        }
        while(zeros--)
        {
            nums[idx++] = 0;
        }
    }