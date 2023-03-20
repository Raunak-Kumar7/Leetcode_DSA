//Brute force: keep dividing by 2

//A number is power of 2 if it has only 1 set bit i.e. leftmost bit
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int cnt = 0;
        while(n>0)
        {
            cnt+= (n&1);
            n = n>>1; //right shift === divide by 2
        }
        if(cnt==1)
            return true;
        return false;
    }


//Method 2:
    //power of 2 has leftmost bit set, power of 2   -1 has all 1s to the right
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n==1 || (n&(n-1))==0); //Use brackets with &
    }