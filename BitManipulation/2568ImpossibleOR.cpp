    //Some Observations:
    //1. When we take OR of 2 --> O/P will always be greater than the larger of the 2 elements --> a|b >=max(a,b) 
    //2. So, If an element is not present in array it has to be formed by elements lesser than itself
    //3. Hence if 1 is not present in array it can never be formed --> Ans = 1
    //4. Similiary on observing if 2 is not present it can not be formed by 1 
    //5. if we have 1,2,3,4 or(1,2,4) we can create any 3 bit number (1-7) as we got bits on all 3 locations
    //6. So our answer will be first power of 2 which is not in array. i.e. power of 2s can not be made using or of any 2 numbers. They have to be already present
    
    int minImpossibleOR(vector<int>& nums) {
        set<int> st;
        for(auto i: nums)
        {
            st.insert(i);
        }
        int check = 1;
        while(true)
        {
            if(st.find(check)!=st.end())
            {
                check*=2;
            }
            else
                break;
        }
        return check;
        
    }