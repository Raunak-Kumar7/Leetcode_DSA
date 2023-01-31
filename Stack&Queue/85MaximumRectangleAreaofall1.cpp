//Based on Largest Rectangle in Histogram 
    //We basically need to find the largest rectangle in each row and rows above it


int largestRectangleInHistogram(vector<int>& heights) {
        stack<int> st;
        int maxA =0;
        int n = heights.size();
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || heights[st.top()]>=heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty())
                    width=i;
                else
                    width = i-(st.top())-1;
                maxA = max(maxA,height*width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& m) {
        int r = m.size();
        int c = m[0].size();
        vector<vector<int>> matrix;
        for(int i=0;i<r;i++)
        {
            vector<int> temp;
            for(int j=0;j<c;j++)
                temp.push_back(m[i][j]-'0');
            matrix.push_back(temp);
        }
        for(int i=1;i<r;i++)
        {
            for(int j =0;j<c;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j] = matrix[i-1][j]+1;
                }
            }
        }
        int ans = 0;
        for(auto vec : matrix)
        {
            ans = max(ans,largestRectangleInHistogram(vec));
        }
        return ans;
    }