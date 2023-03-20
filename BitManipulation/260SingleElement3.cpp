    //When we Xor the entire array we get xor of 2 single elements
    //Now we have to retrieve both the numbers back
    
    //NOW AS BOTH NUMBERS ARE DIFF --> THEY WILL HAVE ATLEAST 1 POSITION WHERE BITS ARE DIFF
    //find such a location of 1 bit wherease one does not have it 
    
    //Then divide the entire array in 2 groups , 1 which has 1 at that location and 1 which doesnt 
    //do xor of both groups separately to get ans
    
    vector<int> singleNumber(vector<int>& nums) {
        
        // // Get the XOR of the two numbers we need to find
        // int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        // // Get its last set bit
        // diff &= -diff;
        vector<int> ans;
        long long x = 0;
        for(auto i:nums)
            x^=i;
        cout<<x;
        x &= -x;    //To make the checker///
        cout<<" "<<x;
        long long x1=0,x2=0;
        for(auto i:nums)
        {
            if((i&x)==0) //== has higher precedence than & so use brackets
                x1^=i;
            else
                x2^=i;
        }
        ans.push_back(x1);
        ans.push_back(x2);
        return ans;
    }