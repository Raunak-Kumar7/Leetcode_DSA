//Code checked by chatgpt on various tcs

//Char stack(Operators)
//Similar code as infix to postfix
    //S1. reverse string
    //S2. apply same infix to postfix (except inside for loop swap (  with )  everywhere)
    //S3. reverse res
    int precedence(char c)
    {
        if(c=='+' || c=='-')
            return 1;
        else if(c=='*' || c=='/')
            return 2;
        else if(c=='^')
            return 3;
    }
    string infixToPrefix(string s) {
        int n = s.size();
        stack<char> st;
        string res = "";
        reverse(s.begin(),s.end());  //S1

        for(int i=0;i<n;i++)
        {
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                res+=s[i];
            else if(s[i]==')')  //opposite
                st.push(s[i]);
            else if(s[i]=='(') //opposite
            {
                while(!st.empty() && st.top()!=')')  //opposite
                {
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty())//pop (
                    st.pop();
            }
            else //operator
            {
                //3 condiditons              //opposite
                while(!st.empty() && st.top()!=')' && precedence(st.top())> precedence(s[i])) //only pop operators with > precedence not >=
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
        reverse(res.begin(),res.end());
        return res;


    }