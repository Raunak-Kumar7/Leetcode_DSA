//Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int left = j+1;
                int right = n-1;
                long long find = (long long)target - nums[i] - nums[j];
                while(left<right)
                {
                    long long target2 = (long long)nums[left] + nums[right];
                    if(target2==find)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[left]);
                        temp.push_back(nums[right]);
                        ans.push_back(temp);
                        //Avoid Duplicates of c
                        while(left<right && temp[2]==nums[left]) left++;
                        //Avoid Duplicates of d
                        while(left<right && temp[3]==nums[right]) right--;   
                    }
                    else if(target2<find)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
                //Avoid duplicates of b
                while(j+1<n && nums[j+1]==nums[j]) j++;
            }
            //Avoid duplicates of a
            while(i+1<n && nums[i+1]==nums[i]) i++;
        }
        return ans;
    }