    //We have to return a substring of string s which is of minimum length
    //it is not neccessary that the order of characters of t in substring of s is same
    // eg O/P : "BANC"    t = "ABC" : here order is not same
    //it is similar to k unique characters only diff here is is that the unique k characters are given as string t
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> mp; //mp stores char of t with freq which denotes what we want in s
        int i=0,j=0;
        int n = s.size();
        bool flag = false; //Any substring not possible
        int ans = INT_MAX; //not initialise with t.size() because answer may not be there
        for(auto it:t)
        {
            mp[it]++;
        }
        int idx = 0; //As we have to return string in this question we take the string of ans length from idx index
        int count = mp.size(); //using count variable to keep track of mp.size(), so that we dont need to calc every time mp.size() //IMPROVES TC
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end()) //decrement only if part of map i.e. part of t
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                {
                    count--;
                }
                //cout<<s[j]<<" "<<mp[s[j]]<<endl;
            }   
            
            //optimise by removing negative chars 
            if(count == 0) //Found a substring which has all characters with same freq
            {
                while(count==0 && i<=j)
                {
                    flag = true;
                    char y = s[i];
                    if(j-i+1<ans) //unique ans
                    {
                        ans = j-i+1;
                        idx = i;
                    }
                    
                    if(mp.find(y)!=mp.end()) //ith char we are removing is part of t
                    { 
                        mp[y]++;
                        if(mp[y]==1) //Update count only if requirement is Positive, it may be the case that we had extra char i.e. negative value
                            count++;
                        i++;
                        //cout<<count<<endl;
                    }
                    if(mp.find(y)==mp.end())
                        i++;
                }
                
                
            }
            j++;
            
        }
        //return ans;   //if length was asked
        //cout<<ans<<endl;
        return flag==true ? s.substr(idx,ans) : "";
    }