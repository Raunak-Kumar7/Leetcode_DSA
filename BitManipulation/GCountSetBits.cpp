int setBits(int n) {
        // Write Your Code here
        int cnt = 0;
        while(n>0)
        {
            cnt+=(n&1);
            n = n>>1;
        }
        return cnt;
    }

//Method 2: Builtin Function
int setBits(int n) {
        return __builtin_popcount(n);
    }