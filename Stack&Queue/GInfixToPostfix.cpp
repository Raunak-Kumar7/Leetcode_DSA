//Char stack(Operators)
    //1. operand --> add to res
    //2. operator --> pop till
    int precedence(char c)
    {
        if(c=='+' || c=='-')
            return 1;
        else if(c=='*' || c=='/')
            return 2;
        else if(c=='^')
            return 3;
    }
    string infixToPostfix(string s) {
        int n = s.size();
        stack<char> st;
        string res = "";
        for(int i=0;i<n;i++)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                res+=s[i];
            else if(s[i]=='(')
                st.push(s[i]);
            else if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty())//pop (
                    st.pop();
            }
            else //operator
            {
                //3 condiditons
                while(!st.empty() && st.top()!='(' && precedence(st.top())>=precedence(s[i]))
                {
                    res+=st.top();
                    st.pop();
                }
                    
                st.push(s[i]); //push the new operator
            }
        }
        while(!st.empty()) //empty the remaining stack to res
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }