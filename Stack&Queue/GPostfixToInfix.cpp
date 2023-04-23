//String stack
    string postToInfix(string s) {
        int n = s.size();
        stack<string> st;
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
                st.push(string(1,s[i]));  //""+s[i] not working
            else
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                st.push("(" + s2 + s[i] + s1 + ")"); //(operand2. operator operand1)
            }
        }
        return st.top();
    }