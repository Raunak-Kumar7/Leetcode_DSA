//Similar to --> Make matrix zeros (keep 1 count vector for rows and 1 for columns to track if all the elements in that row/column are painted or not)
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int l = arr.size();
        int m = mat.size();
        int n = mat[0].size();
        vector<int> r(m,n);
        vector<int> c(n,m);
        map<int,pair<int,int>> loc;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                loc[mat[i][j]] = {i,j};
        }
        for(int i=0;i<l;i++)
        {
            int x = loc[arr[i]].first;
            int y = loc[arr[i]].second;
            mat[x][y] = -1*mat[x][y]; //marked
            r[x]--;
            if(r[x]==0) return i;
            c[y]--;
            if(c[y]==0) return i;
        }
        return -1;
    }