    //Brute Force: Count number of Bits Which are different
    int minBitFlips(int start, int goal) {
        //Optimal : Xor does this for us -> a^b gives 1 wherever bits are diff
        //So now count number of 1s in a^b
        return __builtin_popcount(start^goal);
    }