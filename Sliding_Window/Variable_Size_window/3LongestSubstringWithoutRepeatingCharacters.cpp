//Variable size Sliding Window
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j=0;
        unordered_map<int,int> mp;
        int maxi = 0;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp[s[j]]==1) 
            {
                maxi = max(maxi,j-i+1);
            }   
            else
            {
                while(s[i]!=s[j])
                {
                    mp[s[i]]--;
                    i++;
                }
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return maxi;
    }