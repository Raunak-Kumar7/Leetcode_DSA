//Approach 1: Map
bool isAnagram(string p, string t) {
        unordered_map<char,int> s;
        unordered_map<char,int> ss;
        
        int n1=p.length();
        int n2=t.length();
        if(n1!=n2)
            return false;
        for(int i=0;i<n1;i++)
        {
            s[p.at(i)]++;  
        }
        for(int i=0;i<n2;i++)
        {
            ss[t.at(i)]++;   
        }
        for(auto it:s)
        {
            if(ss.find(it.first)==ss.end())  //not exist 
                return false;
            
            else if(ss[it.first]!=it.second)
                return false;
        }
        return true;
    }


//Approach 2: sorting
bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }