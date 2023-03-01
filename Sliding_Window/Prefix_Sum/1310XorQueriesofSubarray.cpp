    //Here we use concept of Bit manipulation and prefix Sum (Prefix XOR)
    //first we create an array of prefix xors then to find xor of a range we do xor of right index with left -1 which cancels the xor of all element left of left
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n+1); 
        prefix[0] = 0;  //left pad with 0 so that we can do left - 1
        for(int i=0;i<n;i++)
        {
            prefix[i+1] = (prefix[i]^arr[i]);
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++)
        {
            ans[i] = prefix[queries[i][1]+1]^prefix[queries[i][0]];
        }
        return ans;
    }