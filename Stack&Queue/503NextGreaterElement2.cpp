 //Find NGE in Circular Array
 
 //what we can do here is to add nums after nums so we dont need to go in a circular way
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        for(int i=0;i<N;i++)
            nums.push_back(nums[i]);
        //Now nums has nums + nums
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        vector<int> finalAns(N,-1);
        for(int i=0;i<N;i++)
        {
            finalAns[i] = ans[i];
        }
        return finalAns;
    }