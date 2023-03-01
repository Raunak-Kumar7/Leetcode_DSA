    int maxSum(vector<vector<int>>& grid) {
        //Size of hour glass is 3 by 3 only
        //as size is fixed 3x3 we can do it without prefix sum in O(1) space 
        //if it was variable i.e. any odd sized hourglass then use of prefix sum is neccessary
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0;i<m-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                ans = max(ans,(grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]));
            }
        }
        return ans;
        
    }