    //same as LIS as length of words is increasing only diff is to also put a check on insertion/deletion
    //2nd Tabulation Approach
    bool compare(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1!=n2+1) return false; //1 insertion should be there
        int i=0, j=0;
        
        while(i<n1 && j<n2)
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if((i==n1 && j==n2) || s1.substr(0,n2)==s2) //either both end at same time or insertion is done at last
            return true;
        return false;
    }
    int f(int n, vector<string>& words)
    {
        vector<int> dp(n,1); //Min length of LIS = 1
        int maxi = 1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]+1 > dp[i] && compare(words[i],words[j]))
                {
                    dp[i] = dp[j] + 1;
                    maxi = max(dp[i],maxi);
                }
            }
        }
        return maxi;
    }
    static bool comp(string& a, string& b)
    {
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        //we can see in examples that order does not matter so we sort it so that we get smaller strings in the beginning
        //So we need to sort by length not lexicographically
        sort(words.begin(),words.end(),comp);
        return f(n,words);
    }
};