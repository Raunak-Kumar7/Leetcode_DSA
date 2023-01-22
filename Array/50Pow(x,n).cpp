//M1 Brute Force run a loop and  multiply TC O(n)
//use long long nn = n to Handle edge case of INT_MIN 

// M2 Binary Exponentiation O(logn)
double myPow(double x, int n) {
        double ans = 1.0;
        long nn = n; //to prevent overflow if n == INT_MIN
        if(nn<0)
        {
            nn = -1*nn;
        }
        while(nn>0)
        {
            if(nn%2==0)
            {
                x = x*x;
                nn = nn/2;
            }
            else
            {
                ans = ans*x;
                nn = nn-1;
            }
        }
        if(n<0)
        {
            ans = (double)1.0/(double)ans;
        }
        return ans;
    }