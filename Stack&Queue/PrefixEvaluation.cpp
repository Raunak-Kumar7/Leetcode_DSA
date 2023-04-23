// n-->1
    // op1 operand op2
    int evaluatePostfix(string s)
    {
        stack<int> st;
        int l = s.size();
        for(int i=l-1;i>=0;i--)
        {
            if(s[i]>='0' && s[i]<='9')
                st.push(s[i]-'0');
            else //operator
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int temp = 0;
                switch(s[i])
                {
                    case '+':
                        temp = op1 + op2;
                        break;
                    case '-':
                        temp = op1 - op2; //IMPORTANT
                        break;
                    case '*':
                        temp = op1 * op2;
                        break;
                    case '/':
                        temp = op1/op2;
                        break;
                }
                st.push(temp);
            }
        }
        return st.top();
    }