int countCollisions(string directions) {
        int n = directions.size();
        stack<char> st;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(directions[i]=='R' ||directions[i]=='S')
                st.push(directions[i]);
            else if(directions[i]=='L' && !st.empty() && st.top()=='R')
            {
                ans+=2;
                st.pop();
                st.push('S');
            }
            else if(directions[i]=='L' && !st.empty() && st.top()=='S')
            {
                ans+=1;
            }
            else if(directions[i]=='S' &&!st.empty() && st.top()=='R')
            {
                ans+=1;
                st.pop();
                st.push('S');
            }
            
        }
        //1 edge case --> also need to add number of R before a stationary
        bool flag = false;
        while(!st.empty())
        {
            if(st.top()=='S') flag=true;
            if(flag && st.top()=='R') ans++;
            st.pop();
        }
        return ans;
    }