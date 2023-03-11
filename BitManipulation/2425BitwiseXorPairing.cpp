// T.C O(n+m) S.C O(1)
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //in final xor each number comes number of times == length of other array
        //eg [1,2] [3,4,5] --> [1^3, 1^4, 1^5, 2^3, 2^4, 2^5] //we can see 1,2 come 3 times whereas 2,4,5 come 2 times
        //We know property of xor a^a = 0, a^a^a = a ---> odd number of time ,  0-->even numer of times 
        int n1 = nums1.size();
        int n2 = nums2.size();
        int ans = 0;
        
        if(n2%2==1)
        {
            for(int i=0;i<n1;i++)
                ans^=nums1[i];
        }
        if(n1%2==1)
        {
            for(int i=0;i<n2;i++)
                ans^=nums2[i];
        }
        return ans;
    }