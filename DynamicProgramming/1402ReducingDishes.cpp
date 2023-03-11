//Based on pick not pick Concept

    //To maximize product we want that dish with largest satisfaction level has highest time i.e. at last so sort 
    
    //Recursive Approach
    int f(int i,int n,int time, vector<int>& satisfaction)
    {
        if(i==n) //BC reached end of array
            return 0;
        int pick = time*satisfaction[i] + f(i+1,n,time+1,satisfaction);
        int notpick = 0 + f(i+1,n,time,satisfaction);
        return max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        return f(0,n,1,satisfaction); //starting recursion from 0th index because time tracking from start
    }


    
    //Memoized Approach
    int f(int i,int n,int time, vector<int>& satisfaction, vector<vector<int>>& dp)
    {
        if(i==n) //BC reached end of array
            return 0;
        if(dp[i][time]!=-1)
            return dp[i][time];
        int pick = time*satisfaction[i] + f(i+1,n,time+1,satisfaction,dp);
        int notpick = 0 + f(i+1,n,time,satisfaction,dp);
        return dp[i][time] = max(pick,notpick);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n = satisfaction.size();
        //Changing Parameters i,time i--> 0,n time 0-->n
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(0,n,1,satisfaction,dp); //starting recursion from 0th index because time tracking from start
    }