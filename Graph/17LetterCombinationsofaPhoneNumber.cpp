   ///STUDY ITS OPTIMAL APPROACH
   
    //using BFS
    void addchar(map<char,vector<char>>& mp)
    {
        mp['2'].push_back('a');
        mp['2'].push_back('b');
        mp['2'].push_back('c');
        mp['3'].push_back('d');
        mp['3'].push_back('e');
        mp['3'].push_back('f');
        mp['4'].push_back('g');
        mp['4'].push_back('h');
        mp['4'].push_back('i');
        mp['5'].push_back('j');
        mp['5'].push_back('k');
        mp['5'].push_back('l');
        mp['6'].push_back('m');
        mp['6'].push_back('n');
        mp['6'].push_back('o');
        mp['7'].push_back('p');
        mp['7'].push_back('q');
        mp['7'].push_back('r');
        mp['7'].push_back('s');
        mp['8'].push_back('t');
        mp['8'].push_back('u');
        mp['8'].push_back('v');
        mp['9'].push_back('w');
        mp['9'].push_back('x');
        mp['9'].push_back('y');
        mp['9'].push_back('z');
    }
    vector<string> letterCombinations(string digits) {
        set<string> st;
        map<char,vector<char>> mp;
        addchar(mp);
        int n = digits.size();
        vector<string> ans;
        if(n==0) return ans;
        string temp = "";
        for(int i=0;i<n;i++)
        {
            temp = temp +mp[digits[i]][0];
        }
        queue<string> q;
        q.push(temp);
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                string node = q.front();
                q.pop();
                st.insert(node);
                for(int i=0;i<n;i++) //for each index of string
                {
                    for(auto it:mp[digits[i]]) //substitute each possible char for that digit
                    {
                        string child = node;
                        child[i] = it;
                        if(st.find(child)==st.end())
                            q.push(child);
                    }
                }
                countNodes--;
            }
        }
        for(auto it:st)
            ans.push_back(it);
        return ans;
    }


//Do using DFS