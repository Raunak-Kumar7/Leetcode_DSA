bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            char c = s[i];
            if(c=='('||c=='{'||c=='[')
                st.push(c);
            else if((!st.empty())&&((c==')'&&st.top()=='(')||(c=='}'&&st.top()=='{')||(c==']'&&st.top()=='['))) //before checking top or pop checking is stack empty or not is compulsory
                st.pop();
            else
                return false;
        }
            return st.empty();
    }