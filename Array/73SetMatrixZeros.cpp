//Approach 1
//O(n^2) T.C.  O(2n) S.C.

void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(auto i: rows)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=0;
            }
        }
        for(auto i: cols)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][i]=0;
            }
        }
    }


   //O(1)  Approach - using 0th indices of rows and columns as flags if that row/column contains a 0
    //as index [0][0] is intersection for both 0th row and 0th column flag
    //so we use a separate variable as a flag for 0th column
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int zeroCol = -1; 
        //Check if 0th column has a 0
        for(int i=0;i<r;i++)
        {
            if(matrix[i][0]==0)
            {
                zeroCol = 1;//0th column has a 0
            }
        }
        //marking row and column 0th indices
        for(int i=0;i<r;i++)
        {
            for(int j=1;j<c;j++) //dont go in first column because that is handled separately
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        //marking array 0 leaving the first row and column initially until all the rest elements are marked
        //because we dont want to interfere with the flags till then
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(matrix[0][j]==0 || matrix[i][0]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        //if row 0 flag is set
        if(matrix[0][0]==0)
        {
            for(int i=0;i<c;i++)
            {
                matrix[0][i]=0;
                
            }
        }
        //if col 0 flag is set
        if(zeroCol==1)
        {
            for(int i=0;i<r;i++)
            {
                matrix[i][0]=0;
                
            }
        }
    }