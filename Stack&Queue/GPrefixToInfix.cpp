//string stack
    string preToInfix(string s) {
       int n = s.size();
       stack<string> st;
       for(int i=n-1;i>=0;i--)  // i--> n-1 to 0
       {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                st.push(string(1,s[i]));
            else
            {
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push("(" + op1 + s[i] + op2 + ")");  // (operand1 operator operand2)
            }
       }
       return st.top();
    }