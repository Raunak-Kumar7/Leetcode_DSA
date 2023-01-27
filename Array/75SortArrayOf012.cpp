// Sort Normally O(nlogn)

/////OR/////
//O(2*n) Approach
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


//Optimised Approach
    //O(1*n) T.C. Approach
    //Dutch National Flag Algorithm
    void sortColors(vector<int>& nums){
        //Take 3 pointers low and mid point 0, high points last index
        int n = nums.size();
        int low = 0; //All elements left of low i.e. [0,low-1] are 0s
        int mid = 0;
        int high = n-1; //All elemnts right of high [high+1,n-1] are 2s
        
        while(mid<=high) //Run while loop till mid pointer CROSSES the high pointer
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++; //incremenet both the low and mid pointer
            }
            else if(nums[mid]==1)
            {
                mid++; //no Swapping simply increment mid
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);  //here only decrement the high pointer
                high--;
            }
        }
        
    }