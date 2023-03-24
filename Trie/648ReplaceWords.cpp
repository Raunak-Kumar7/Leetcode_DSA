 //Also Implement Using Trie O(n) O(n)
    
    //Brute Force O(n^2) O(n)
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        for(auto i:dictionary)
        {
            st.insert(i);
        }
        sentence = sentence+" ";
        int l = sentence.size();
        string res = "";
        string w = "";
        for(int i=0;i<l;i++)
        {
            char ch = sentence.at(i);
            if(ch!=' ')
            {
                w = w+ch;
                if(st.find(w)!=st.end())
                {
                    res+=w+" ";
                    while(sentence.at(i)!=' ')
                        i++;
                    w = "";
                }
            }
            else
            {
                res+=w+" ";
                w = "";
            }
            
        }
        int len = res.size();
        
        return res.substr(0,len-1);
    }



//Trie Approach
// O(n) O(n)

