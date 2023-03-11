//Based on Prime factorisation, (LC 2521)

//Using Number Theory
    //If Number is Prime --> we need to copy only once and keep pasting --> ans = n(bcz no prime factors)
    //If number is Not Prime 
    // eg. n = 10 --> we first need to make largest prime factor of n by single copy paste then copy the largest prime factor and keep pasting
    //     10 -->(2,5) --> first make 5 using 5 operations(1 copy 4 paste) then 2 operations (1 copy 1 paste)
    //     12 -->(2,2,3) --> first make 3 using 3 operations(1 copy 2 paste) then 4 operations(1 copy 3 paste)
    //     16 -->(2,2,2,2) --> first make 2 using 2 operations(1 copy 1 paste) then 6 operations(1 copy 1 paste 1 copy 1 paste 1 copy 1 paste )
    //     so basically we are returning sum of prime factors
    
    //M1 O(n)
    //M3 O(logn) using sieve
    //O(sqrt(n)) approach 
    int minSteps(int n) {
        if(n==1) return 0;
        int sum = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    sum+=i;
                    cout<<sum<<" ";
                    n=n/i;
                }
            }
        }
        if(n>1)
            return sum+n;//To handle the case if the number is prime itself or like 12 where last prime factor is not captured 
        return sum;
        
        
    }''