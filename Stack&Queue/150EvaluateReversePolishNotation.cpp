//Evaluate postfix expression
    //1-->n
    //op2 operand op1
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i=0;i<n;i++)
        {
            char c = tokens[i][0];
            if(tokens[i].size()==1 && (c=='+'||c=='-'||c=='*'||c=='/')) //need to check size = 1 else negative number also satisfies
            {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int temp = 0;
                switch(tokens[i][0])
                {
                    case '+':
                        temp = op2 + op1;
                        break;
                    case '-':
                        temp = op2 - op1;
                        break;
                    case '*':
                        temp = op2 * op1;
                        break;
                    case '/':
                        temp = op2 / op1;
                        break;
                }
                st.push(temp);
            }
            else //Writing this as else to handle numbers with signs 
                st.push(stoi(tokens[i])); // can be multidigit
        }
        return st.top();
    }