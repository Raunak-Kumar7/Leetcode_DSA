 //same code as largest rectangle only change is take height = width
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
                int ar = height<width? height*height : width*width;//only change is this to take sqaure of min
                maxA = max(maxA,ar);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalSquare(vector<vector<char>>& m) {
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