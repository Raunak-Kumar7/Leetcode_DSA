vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool> sieve(N+1,0);   //bool to save space and time
        sieve[0] = 1; //1 means non prime
        sieve[1] = 1;
        for(int i = 2;i*i<=N;i++) //eg n = 50 , we need to run loop till 7 only 
        {
            for(int j = i*i;j<=N;j+=i) //we start by marking from i^2, eg for i = 3 till 9 all will be already marked
            {
                sieve[j] = 1;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<=N;i++)
        {
            if(sieve[i]==0)
                ans.push_back(i);
        }
        return ans;
    }