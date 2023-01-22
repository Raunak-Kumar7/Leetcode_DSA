//Greater than n/3

//M1 Brute Force O(n^2)
//Check frequency of each element

//M2 O(n) , O(n)
//Use Hashmap to store frequency

//M3 Optimised O(n)
//Boyre Moore Approach


vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1 =-1;
        int num2 =-1;
        int count1 =0;
        int count2 =0;
        // at max there can be 2 majority elements
        //as in majority element1 it will give candidates for majority element no confirmed majority elements so we need to check 
        for(int i=0;i<n;i++)
        {//5 cases
            int ele = nums[i];
            if(ele == num1)
                count1++;
            else if(ele ==num2)
                count2++;
            else if(count1==0)
            {
                num1 = ele;
                count1 =1;
            }
            else if(count2 ==0)
            {
                num2 = ele;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        int check = n/3;
        int f1=0,f2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                f1++;
            else if(nums[i]==num2)
                f2++;
        }
        vector<int> ans;
        if(f1>check)
            ans.push_back(num1);
        if(f2>check)
            ans.push_back(num2);
        return ans;
        
    }