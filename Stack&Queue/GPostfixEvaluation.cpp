// 1-->n 
    // op2 operand op1
    int evaluatePostfix(string s)
    {
        stack<int> st;
        int l = s.size();
        for(int i=0;i<l;i++)
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
                        temp = op2 + op1;
                        break;
                    case '-':
                        temp = op2 - op1; //IMPORTANT
                        break;
                    case '*':
                        temp = op2 * op1;
                        break;
                    case '/':
                        temp = op2/op1;
                        break;
                }
                st.push(temp);
            }
        }
        return st.top();
    }