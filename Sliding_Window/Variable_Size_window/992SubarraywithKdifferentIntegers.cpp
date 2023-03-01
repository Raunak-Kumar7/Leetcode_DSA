//code with alisha
    //Count in variable size sliding window
    //Finding subarrays with k diff integers is difficult 
    //But finding count of subarrays with AT MOST k diff integers is easier
    //subarrays with k diff integers --> atmost(k)-atmost(k-1)
    int atmostk(vector<int>& nums, int k)
    {
        int n = nums.size();
        int i=0,j=0; 
        unordered_map<int,int> mp;
        int count=mp.size();
        int ans = 0;
        while(j<n) 
        {
            //keep expanding right boundary till count<=k
            mp[nums[j]]++;
            count = mp.size();
            if(count<=k) //if count is <=k it means at most 3 are there so we take all the subarray till here 
            {
                ans+=j-i+1;
                j++;
            }  
            else if(count>k) //shrink
            {
                
                while(count>k)
                {
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    {
                        mp.erase(nums[i]);
                        count--;
                    }
                       
                    i++;
                }
                ans+=j-i+1; // after making a valid subarray update the answer
                j++;
            }
                
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostk(nums,k)-atmostk(nums,k-1);
    }