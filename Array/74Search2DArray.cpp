//M1 Brute force Search all the elements O(n^2)

//M2 O(m+n) as rows are sorted and first index of columns are also sorted we first check which row can have our element 
//then linearly traverse that row
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  //no of rows
        int n = matrix[0].size();
        int i;
        if(m==1)
        {
            for(int i=0;i<n;i++)
            {
                if(matrix[0][i]==target)
                    return true;
            }
            return false;
        }
        for(i=0;i<m;i++)
        {
            if(matrix[i][0]>target)
                break;
            
        }
        int ind =i-1;
        if(ind==-1)
            return false;
        for(int i=0;i<n;i++)
        {
            if(matrix[ind][i]==target)
                return true;
        }
        return false;
        
    }

    

//M3 O(log(m*n)) Binary Search Approach , Start top right OR Bottom Left

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n-1;
        while(r>=0 && r<m && c>=0 && c<n)
        {
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]>target)
                c--;
            else
                r++;
        }
        return false;
    }