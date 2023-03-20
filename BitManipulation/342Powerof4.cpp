    //power of 2 have all 0 and only one 1
    //power of 4 is same as power of 2 , only diff is that it has even number of 0
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        int cntZeros=0;
        int cntOnes=0;
        for(int i=n;i>0;i=i/2)
        {
            if(i&1==1)
                cntOnes++;
            else
                cntZeros++;
        }
        if(cntOnes>1 || cntZeros%2==1)
            return false;
        return true;
        
    }