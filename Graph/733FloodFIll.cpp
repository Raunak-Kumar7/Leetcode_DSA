//Each cell is a node ans is represented by {row,col}
//Using BFS
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> ans = image; //not modifying the input vec
        //in this we have to color only the 1 connected compoennt which has {sr,sc}
        vector<vector<int>> visited(m,vector<int> (n,0));
        //we dont need multiple components so not writing the for loop
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};

        int initialColor = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ans[sr][sc] = color;
        visited[sr][sc] = 1;

        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes > 0)
            {
                pair<int,int> node = q.front();
                q.pop();
                for(int i=0;i<delrow.size();i++)
                {
                    int childR = node.first + delrow[i];
                    int childC = node.second + delcol[i];
                    //children need to satisfy 3 conditions 
                    if((childR >= 0 && childR < m && childC >= 0 && childC < n) && !visited[childR][childC] && image[childR][childC] == initialColor)
                    {
                        q.push({childR,childC});
                        ans[childR][childC] = color;
                        visited[childR][childC] = 1;
                    }
                    countNodes--;
                }
            }
        }
        return ans;
    }




//Using DFS
    void dfs(vector<vector<int>>& image, vector<vector<int>>& ans, vector<vector<int>>& visited, int r, int c , int m, int n, vector<int> delrow,vector<int> delcol, int color, int initialColor)
    {
        // root
        visited[r][c] = 1;
        ans[r][c] = color;

        //call all children
        for(int i=0;i<delrow.size();i++)
        {
            int childR = r + delrow[i];
            int childC = c + delcol[i];
            //satisy 3 condition
            if((childR >=0 && childR < m && childC >= 0 && childC <n) && !visited[childR][childC] && image[childR][childC] == initialColor)
            {
                dfs(image,ans,visited,childR,childC,m,n,delrow,delcol,color,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        //we have to color only one component connected to it
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image; //not modifying the original array
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,-1,0,1};
        dfs(image,ans,visited,sr,sc,m,n,delrow,delcol,color,initialColor);
        return ans;
    }