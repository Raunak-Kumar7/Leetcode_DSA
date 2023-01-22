vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r(numRows); //generate 2d vector of rows = n

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);         //resize each 1D vector to size i+1
            r[i][0] = r[i][i] = 1;      //first and last element of each row =1
  
            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }
        
        return r;
    }


////////////////////OR////////////////////
vector<vector<int>> generate(int numRows) {
        vector<int> a;
        vector<vector<int>> ans;
        a.push_back(1);
        ans.push_back(a);
        if(numRows==1)
            return ans;
        
        vector<int> b;
        b.push_back(1);
        b.push_back(1);
        ans.push_back(b);
         if(numRows==2)
            return ans;
        
        
        int n=numRows;
        for(int i=3;i<=n;i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for(int j=0;j<i-2;j++)
            {
                temp.push_back(b[j]+b[j+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
             b=temp;
        }
        return ans;
    }