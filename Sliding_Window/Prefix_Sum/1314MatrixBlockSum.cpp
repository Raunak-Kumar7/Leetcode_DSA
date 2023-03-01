    //PREFIX SUM ON 2D MATRIX
    
    //Similar to 304,1292,
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        //Calculate prefix sum
        vector<vector<int>> prefix;
        for(auto i:mat)
        {
            int sum = 0;
            vector<int> temp;
            for(auto j:i)
            {
                sum+=j;
                temp.push_back(sum);
                //cout<<sum<<" ";
            }
            //cout<<endl;
            prefix.push_back(temp);
        }
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int c1 = max(j-k-1,0); 
                int c2 = min(j+k,m-1);
                for(int range = max(0,i-k);range<=min(n-1,i+k);range++)//denotes rows to take
                {
                    ans[i][j] += prefix[range][c2];
                    if(j-k>0)
                        ans[i][j]-=prefix[range][c1];
                }
            }
        }
        return ans;
    }