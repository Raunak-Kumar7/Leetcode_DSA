//Approach 1: Brute Force: for every bar find left smaller and right smaller(INDICES)
    //then do (right smaller - left smaller -1)*a[i] 
    // T.C. O(n^2) S.C. O(1)


    //T.C O(n) S.C. O(n)
    int largestRectangleArea(vector<int>& heights) {
        //Approach 2: using NSE approach , just doing preprocessing in Approach 1
        //to calc right smaller and left smaller
        //In Nse we dont need the height of the pillar, For width we just need INDICES
        int n = heights.size();
        vector<int> nser(n,n); //n if nser doesnt exist
        vector<int> nsel(n,-1); //-1 if nsel doesnt exist
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nser[i]=st.top();
            }
            st.push(i);//as we need indices for width we push indices in stack
        }
        while(!st.empty())
            st.pop();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nsel[i] = st.top();
            }
            st.push(i);
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans = max(ans,(nser[i]-nsel[i]-1)*heights[i]);
        }
        return ans;
    }

//Optimised Approach