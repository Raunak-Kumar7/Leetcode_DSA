    // 0/1 KnapSack 
    //Recursive Solution
    long long f(int i, int n, vector<vector<int>>& questions)
    {
        //Base Case
        if(i>=n)
            return 0;
        
        return max(questions[i][0] + f(i + questions[i][1] + 1, n , questions),
                  0 + f(i+1, n, questions));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return f(0,n,questions); //going forward 
    }




    // 0/1 KnapSack 
    //Memoized Solution
    long long f(int i, int n, vector<vector<int>>& questions,vector<long long>& dp)
    {
        //Base Case
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = max(questions[i][0] + f(i + questions[i][1] + 1, n , questions, dp),
                  0 + f(i+1, n, questions, dp));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1); //memoising using 1d dp (only 1 changing variable --> index)
        return f(0,n,questions,dp); //going forward 
    }



    // 0/1 KnapSack 
    //Tabulation Solution (opposite of recursive tree) 
    long long f(int n, vector<vector<int>>& questions,vector<long long>& dp)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(i + questions[i][1] + 1 < n)
                dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1] ,0 + dp[i+1]);
            else
                dp[i] = max(1LL*questions[i][0], 0 + dp[i+1]);  //handles the case for the elemnents which dont have an element brainpower away but still can pick or notpick
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0); //n+1 size array for tabulation
        return f(n,questions,dp);
    }


//As we are always going i+brainpower ahead 
//We will atleast require a 1d dp always bcz we may access any of the ahead elements
//therfore no further space optimisation possible