    //https://leetcode.com/problems/increment-submatrices-by-one/discuss/3052675/Python3-Sweep-Line-(Range-Addition-w-Visualization)-Clean-and-Concise
    //Line Sweep(Prefix Sum) on matrix (Matrix Sweep)
    // perform OP on Intervals
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int len = queries.size();
        vector<vector<int>> ans(n,vector<int> (n,0));
        for(int i=0;i<len;i++)
        {
            ans[queries[i][0]][queries[i][1]]++;
            if(queries[i][2]+1<n && queries[i][3]+1<n) ans[queries[i][2]+1][queries[i][3]+1]++;
            
            if(queries[i][3]+1<n) ans[queries[i][0]][queries[i][3]+1] -=1; //sweep line along column
            if(queries[i][2]+1<n) ans[queries[i][2]+1][queries[i][1]] -=1; //sweep line along row
        }
        //Made Prefix Sum array
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[i][j] += ans[i-1][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                ans[i][j] += ans[i][j-1];
            }
        }
        return ans;
    }