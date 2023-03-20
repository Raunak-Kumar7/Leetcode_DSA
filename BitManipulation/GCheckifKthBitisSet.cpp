    //Method1 : O(32) //remove k bits from right by divide by 2
    //Method2 : Prepare Mask
    //O(1) Approach
    bool checkKthBit(int n, int k)
    {
        int mask = 1<<k;
        return ((n&mask)==mask); //Remember == has higher priority than Bitwise
    }