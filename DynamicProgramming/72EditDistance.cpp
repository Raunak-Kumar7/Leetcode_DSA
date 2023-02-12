    //Recursion approach 
    int f(int i, int j, string& word1, string& word2)
    {
        if(j<0) return i+1; //s2 is exhausted  no of operations left  = i+1 deletions of s1
        else if(i<0) return j+1;  //s2 is exhausted  no of operations left  = j+1 insertions of s2
        if(word1[i]==word2[j]) //matched so dont need to perform any operation
            return 0 + f(i-1,j-1,word1,word2);
        else //if not match return min of all 3 operations
            return 1 + min(f(i,j-1,word1,word2),min(f(i-1,j,word1,word2),f(i-1,j-1,word1,word2)));
                            // insert.              Delete                 Replace
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return f(m-1,n-1,word1,word2);
    }


    //Memoization approach 
    int f(int i, int j, string& word1, string& word2, vector<vector<int>>& dp)
    {
        if(j<0) return i+1; //s2 is exhausted  no of operations left  = i+1 deletions of s1
        else if(i<0) return j+1;  //s2 is exhausted  no of operations left  = j+1 insertions of s2
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) //matched so dont need to perform any operation
            return dp[i][j] = 0 + f(i-1,j-1,word1,word2,dp);
        else //if not match return min of all 3 operations
            return dp[i][j] = 1 + min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));
                            // insert.              Delete                 Replace
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        //changing parameters = 2 i,j
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(m-1,n-1,word1,word2,dp);
    }


    //Tabulation  approach 
    int f(int m, int n, string& word1, string& word2, vector<vector<int>>& dp)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0)
                        dp[i][j] = j; //right shift by 1 so instead of j+1 --> j
                    if(j==0)
                        dp[i][j] = i;
                }
                else
                {
                    if(word1[i-1]==word2[j-1]) //matched so dont need to perform any operation
                        dp[i][j] = 0 + dp[i-1][j-1];
                    else //if not match return min of all 3 operations
                        dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
        
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        //changing parameters = 2 i,j
        //right shift by 1
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return f(m,n,word1,word2,dp);
    }


    //Space Optimisation  approach 
    int f(int m, int n, string& word1, string& word2)
    {
        //we only need one previous row
        vector<int> prev(n+1,0);
        for(int i=0;i<=m;i++)
        {
            vector<int> curr(n+1,-1);
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    if(i==0)
                        curr[j] = j; //right shift by 1 so instead of j+1 --> j
                    if(j==0)
                        curr[j] = i;
                }
                else
                {
                    if(word1[i-1]==word2[j-1]) //matched so dont need to perform any operation
                        curr[j] = 0 + prev[j-1];
                    else //if not match return min of all 3 operations
                       curr[j] = 1 + min(curr[j-1],min(prev[j],prev[j-1]));
                }
            }
            prev = curr;
        }
        return prev[n];
    }
        
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        //changing parameters = 2 i,j
        //right shift by 1
        return f(m,n,word1,word2);
    }
    