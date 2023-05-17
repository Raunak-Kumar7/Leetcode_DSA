//Bitwise and of all positive will be >=0
    //if AND of any 2 elements is 0 --> And of entire combination will be 0
    // becuase a&0 = 0
    //therefore we want a set where all pairs of elements and is not 0
    //to have this true we want the elements
    //to make a combination we need to have atleast 1 bit where there are all 1s(in all elements of combination), only then AND of all numbers in combination will give at that bit 1 and number will be non 0
    int largestCombination(vector<int>& candidates) {
        //32 bit number
        int n = candidates.size();
        int maxi = 0;
        for(int i=0;i<32;i++)
        {
            int mask = 1<<i;
            int count = 0;
            for(int j=0;j<n;j++)
            {
                if(mask&candidates[j])
                    count++;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }