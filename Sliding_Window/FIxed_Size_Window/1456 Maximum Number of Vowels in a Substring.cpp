// Based on fixed window count frequency 

//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        int ans =0;
        int count =0;
        set<char> st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        while(j<n)
        {
            if(st.find(s[j])!=st.end())
            {
                count++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                ans = max(ans,count);
                if(st.find(s[i])!=st.end())
                {
                    count--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};