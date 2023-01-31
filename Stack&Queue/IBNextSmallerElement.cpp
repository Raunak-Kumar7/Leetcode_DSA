vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=A[i]) //same code as nge only sign is diff >= 
        {
            st.pop();
        }
        if(!st.empty())
        {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}
