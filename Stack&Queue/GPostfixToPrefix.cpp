//Same as postfix to infix --> only differnce is expression oper op1 op2 like prefix 
//& no brakcets 
string postToPre(string s) {
        int n = s.size();
        stack<string> st;
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z'))
                st.push(string(1,s[i]));
            else
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                st.push( s[i] + s2 + s1 ); //(operator operand2  operand1)
            }
        }
        return st.top();
    }