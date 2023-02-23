   int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        unordered_map<char,int> mp;
        int i=0,j=0;
        int ans = -1;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size()<k)
                j++;
            
            else if(mp.size()==k) //Not remove if k unique chars found becuse next char may be duplicate
            {
                ans = max(ans,j-i+1);
                j++;
            }
            else if(mp.size()>k)
            {
                while(mp.size()>k)
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                ans = max(ans,j-i+1);
                j++;
            }
        }
        return ans;
    }