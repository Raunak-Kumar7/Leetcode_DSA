  //Based on Prime factorisation
  
   //we stop when the number itself is prime 
    int primeFactorSum(int n)
    {
        int sum = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    sum+=i;
                    n = n/i;
                }
            }
        }
        if(n>1)
            return sum+n;
        return sum;
    }
    bool isPrime(int n)
    {
        if(n==1) return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    int smallestValue(int n) {
        int mini = INT_MAX;
        while(isPrime(n)==false)
        {
            int x = primeFactorSum(n);
            mini = min(mini, x);
            if(x==n) //cycle
                break;
            n = x;
        }
        return n;   
    }