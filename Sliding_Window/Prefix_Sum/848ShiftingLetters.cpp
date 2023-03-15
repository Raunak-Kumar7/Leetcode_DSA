string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        //making the shifts array as prefix array
        //WE SHIFT IN MULTIPLES OF 26
        shifts[n-1]%=26;
        for(int i=n-2;i>=0;i--)
        {
            shifts[i] = (shifts[i]%26+shifts[i+1]%26)%26;
        }
        //still value of char can go beyond 122 but it will be adjusted by doing -26
        for(auto i:shifts)
            cout<<i<<" ";
        for(int i=0;i<n;i++)
        {
            int x = s[i];
            if(x+shifts[i]>122)
                s[i] = char(x+shifts[i]-26);
            else
                s[i] = s[i]+shifts[i];
        }
        return s;
    }