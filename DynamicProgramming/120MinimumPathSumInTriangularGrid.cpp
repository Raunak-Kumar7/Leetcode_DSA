//Question is similar to Unique path in a grid
    //Only difference is that it has a variable ending Point
    //Aproach 1: Recursive try out all paths (Top Down)  T.C. O(2(m*m) actually less than m*m == number of elements)
    //S.C. O(m)Path Length
    int f(int i, int j, int m, vector<vector<int>>& triangle)
    {
        if(i==m-1)//Reached Last row Base Case
        {
            return triangle[i][j];
        }
        //We can move down or right, on moving right we never go out of bound 
        int down = triangle[i][j] + f(i+1,j,m,triangle);
        int right = triangle[i][j] + f(i+1,j+1,m,triangle);
        return min(down,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //As starting point is fixed we always start from fixed point
        int m = triangle.size();
        return f(0,0,m,triangle);
    }

//Aproach 2: Memoized  (Top Down) T.C. O(m*m) S.C. O(m*m + m)
    int f(int i, int j, int m, vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        if(i==m-1)//Reached Last row Base Case
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j]; 
        //We can move down or right, on moving right we never go out of bound 
        int down = triangle[i][j] + f(i+1,j,m,triangle,dp);
        int right = triangle[i][j] + f(i+1,j+1,m,triangle,dp);
        return dp[i][j] = min(down,right); //S2
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //As starting point is fixed we always start from fixed point
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int> (m,-1));  //S1
        return f(0,0,m,triangle,dp);
    }

//Aproach 3: Tabulation  (Bottom Up of recursion tree)  T.C. O(m*m) S.C. O(m*m)
    int f(int m, vector<vector<int>>& triangle,vector<vector<int>>& dp)
    {
        for(int i=m-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)  //Dont initialize j= m-1 bcz triangular not square
            {
                if(i==m-1) //Base case To initialisation
                    dp[i][j] = triangle[i][j];
                else
                {
                    int down = triangle[i][j];
                    int right = triangle[i][j];
                    if(i<m-1) down+=dp[i+1][j];
                    if(i<m-1) right+=dp[i+1][j+1];
                    dp[i][j] = min(down,right);
                }
            }
        }
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //As starting point is fixed we always start from fixed point
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int> (m,-1));  //S1
        return f(m,triangle,dp);
    }


//Aproach 4: Tabulation->Space Optimisation  (Bottom Up of recursion tree) T.C. O(m*m) S.C. O(m)
    int f(int m, vector<vector<int>>& triangle)
    {
        vector<int> nextRow(m,1e8); //min so initialise with a large number
        for(int i=m-1;i>=0;i--)
        {
            vector<int> curr(m,-1);
            for(int j=i;j>=0;j--)  //Dont initialize j= m-1 bcz triangular not square
            {
                if(i==m-1) //Base case To initialisation
                    curr[j] = triangle[i][j];
                else
                {
                    //We only need one bottom row of dp array
                    int down = triangle[i][j];
                    int right = triangle[i][j];
                    if(i<m-1) down+=nextRow[j];
                    if(i<m-1) right+=nextRow[j+1]; //here both are next row
                    curr[j] = min(down,right);
                }
            }
            nextRow = curr;
        }
        return nextRow[0];  //nextrow = curr done
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        //As starting point is fixed we always start from fixed point
        int m = triangle.size();
        return f(m,triangle);
    }