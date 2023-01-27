// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

int merge(vector<int>& nums, int low, int mid, int high)
    {
        int cnt =0;
        int j = mid+1;  // j is the index for the right half as in dry run
        for(int i=low;i<=mid;i++) //i is the index for the left half
        {
            while(j<=high && nums[i]>2LL*nums[j])  //2LL convert it to long long
            {
                j++;
            }
            cnt+=(j-(mid+1));  //in this we are moving in right half i.e. j , till we find element which falses the condition, as soon as we find such an element means all element bw mid+1,j satisfy the condition
        }
        //calculation done
        //NOW MERGE
        vector<int> temp;
        int left = low;
        int right = mid+1;
        while(left<=mid && right<=high)
        {
            if(nums[left]<=nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid)
        {
            temp.push_back(nums[left++]);
        }
        while(right<=high)
        {
            temp.push_back(nums[right++]);
        }
        for(int i=low;i<=high;i++)  //storing the solution back in nums array
        {
            nums[i] = temp[i-low];  //we are doing i-low because temp array starts from 0 whereas nums may not neccessarily 
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums,int low,int high)
    {
        if(low>=high) return 0;    //0 or 1 element
        int mid = (low+high)/2;
        int count=0;
        count = mergeSort(nums,low,mid);    //on left half Divide
        count+= mergeSort(nums,mid+1,high);  //on right half Divide
        count+= merge(nums,low,mid,high);    //Merge 2 halves
        return count;
    }
    int reversePairs(vector<int>& nums) { //approach striver,in copy
        return mergeSort(nums,0,nums.size()-1);
    }