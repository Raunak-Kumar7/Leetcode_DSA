   string getSmallestString(int n, int k) {
        //Length of the string is n
        //numeric value i.e. sum of chars = k (k<=26n given)
        //therefore we need to keep given maximum value from right making sure that we keep enough value of k to suffice the length = n
        string res = string(n,'a');
        for(int i=n-1;i>=0;i--)
        {
            int z = (i)*1;
            int c = min(k-z,26);
            k = k-c;
            char ch = char('a' + (c - 1));
            res[i] = ch ; 
        }
        return res;
    }