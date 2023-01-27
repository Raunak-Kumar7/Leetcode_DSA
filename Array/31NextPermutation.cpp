//Approach 1
//use inbuilt STL function

void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }

//Approach 2 
//Implementation of next_permutation
//STEPS
//1. Start from Right to Left and find the first index where 2 numbers are like 15479864 i.e. right element bigger than left element
//2. Store index of 7 in idx (3)
//3. To the right of 7 find element which is just greater than 7 (8)
//4. Swap the just greater element and 7 (15489764)
//5. Incremenet index by 1 --> idx++ (4)
//6. Sort the arr from nums.begin()+idx to nums.end() (15484679)

    static bool myfunction (int i,int j) { return (i<j); }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                idx=i-1;
                break;
            }
        }
        if(idx<0)
            reverse(nums.begin(),nums.end());  //instead of sort use reverse O(n)
        //find min to right
        else{
            
        int mn = INT_MAX;
        int pos=-1;
        for(int i=n-1;i>=idx+1;i--)
        {
            if(nums[i]<mn && nums[i]>nums[idx])//smallest &greater
            {
                mn=nums[i];
                pos=i;
            }
        }
        int temp = nums[idx];
        nums[idx]=nums[pos];
        nums[pos]=temp;
        idx++;
        reverse(nums.begin()+idx,nums.end());
        }
    }