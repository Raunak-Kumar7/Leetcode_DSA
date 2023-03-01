    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        //we need to Create the prefix Xor matrix then return Max Xor 
        //This prefix xor is of best format --> O(1) to get ans 
        //To generate prefix xor matrix prefix[i][j] = 1) do row wise prefix 2) do column wise prefix
        
        //We dont need to create the original matrix, we can just keep pushing in pq
        
        //We want to get the kth largest element so use min heap
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix(m+1,vector<int>(n+1,0)); //padded with 0
        priority_queue<int,vector<int>, greater<int>> pq;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                prefix[i+1][j+1] = matrix[i][j]^prefix[i][j]^prefix[i][j+1]^prefix[i+1][j]; //instead of doing first row wise then column wise --> do in 1 step using diagram
                pq.push(prefix[i+1][j+1]);
                if(pq.size()>k)
                    pq.pop();
            }    
        }
        return pq.top();
    }