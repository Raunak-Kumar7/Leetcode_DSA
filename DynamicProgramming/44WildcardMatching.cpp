    //Recursive Approach
    int f(int i, int j, string& s, string& p)
    {
        //base Cases x3
        if(i<0 && j<0) return true; //both finished simultaneously
        else if(i<0 && j>=0) return false;  // s is finished but p is remaining
        else if(j<0 && i>=0) //p is finished but s may either be empty or consists of only *
        {
            for(int x=0;x<=i;x++)
            {
                if(s[x]!='*')
                    return false;
            }
            return true;
        }
        
        if(s[i]==p[j] || s[i]=='?') //Match
            return f(i-1,j-1,s,p);
        else 
        {
            if(s[i]=='*') // 0 or more character
                return ((f(i-1,j,s,p)||f(i,j-1,s,p)));
            else 
                return false; // if not match and neither ? *
        }
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return f(n-1,m-1,p,s); //second string consists of * and ? so swapped
    }


    //Memoize
    int f(int i, int j, string& s, string& p,vector<vector<int>>& dp)
    {
        //base Cases x3
        if(i<0 && j<0) return true; //both finished simultaneously
        else if(i<0 && j>=0) return false;  // s is finished but p is remaining
        else if(j<0 && i>=0) //p is finished but s may either be empty or consists of only *
        {
            for(int x=0;x<=i;x++)
            {
                if(s[x]!='*')
                    return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || s[i]=='?') //Match
            return dp[i][j] = f(i-1,j-1,s,p,dp);
        else 
        {
            if(s[i]=='*') // 0 or more character
                return dp[i][j] = ((f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp)));
            else 
                return dp[i][j] = false; // if not match and neither ? *
        }
    }
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return f(n-1,m-1,p,s,dp); //second string consists of * and ? so swapped
    }

