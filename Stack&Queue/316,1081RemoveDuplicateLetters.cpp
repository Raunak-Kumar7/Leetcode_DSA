string smallestSubsequence(string s) {
        //first we need to find all the characters that come 
        //Hashmap O(26)
        int n = s.size();
        vector<int> f(26,0); //Stores Frequency
        for(auto it: s)
        {
            f[it-'a']++;
        }
        //to have a smallest lexicographic order we need to make sure that if eg a 'z' is coming more than once, we should pick its last instance
        vector<bool> exist(26,false); //To check if char exists in Stack 
        stack<char> st;
        for(auto it:s)
        {
            while(!st.empty() && st.top()>=it && f[st.top()-'a']>=1 && exist[it-'a']==false) //removing letters which can come afterwards//even removing when same bcz we need to decrease the count
            {
                exist[st.top()-'a']=false;
                st.pop();
            }
            if(exist[it-'a']==false)
            {
                exist[it-'a']=true;
                st.push(it);
                f[it-'a']--;
            }
            else if(exist[it-'a']==true && f[it-'a']>0) //if the character already exists in stack and we dont want to use more of its instance just walk past it decreasing its count eg "abacb"
            {
                f[it-'a']--;
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }