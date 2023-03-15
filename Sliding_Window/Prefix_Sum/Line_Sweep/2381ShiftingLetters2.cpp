string shiftingLetters(string s, vector<vector<int>>& shifts) {
       //Store net shifts of a character in a prefix array
        int n = shifts.size();
        int l = s.size();
        vector<int> prefix(l+1,0);
        for(int i=0;i<n;i++)
        {
            int l = shifts[i][0];
            int r = shifts[i][1];
            int dir = shifts[i][2];
            if(dir==0) dir = -1; //shift left
            prefix[l]+=dir;
            prefix[r+1]-=dir;
            
        }
        
        for(int i=1;i<=l;i++)
        {
            prefix[i] = prefix[i] + prefix[i-1];
        }
        //first we need to bring all values withing [-25,25]
        for(int i=0;i<=l;i++)
        {
            if(prefix[i]<-25)
            {
                prefix[i] = (26-((-1*prefix[i])%26))%26;
            }
                
            else if(prefix[i]>25)
                prefix[i]%=26;
        }
        //[0,25]
        for(int i=0;i<=l;i++)
        {
            if(prefix[i]<0)
                prefix[i]+=26;
        }
        //still value of char can go beyond 122 but it will be adjusted by doing -26
        for(int i=0;i<l;i++)
        {
             int x = s[i];
            if(x+prefix[i]>122)
                s[i] = char(x+prefix[i]-26);
            else
                s[i] = s[i]+prefix[i];
             
        }
        return s;
    }