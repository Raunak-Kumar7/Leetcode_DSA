// Based on Count Occurence of Anagrams

//Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//In other words, return true if one of s1's permutations is the substring of s2.

// https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char,int> mp; //to store frequencies of the characters in p
        int i=0,j=0;
        int n = s.size();
        int k = p.size();
        for(int i=0;i<k;i++)
        {
            mp[p[i]]++;
        }
        int count = mp.size(); //to store size of map , when 0 means p==s
        while(j<n)
        {
            char c = s[j];
            if(mp.find(c)!=mp.end())
            {
                mp[c]--;
                if(mp[c]==0)
                {
                    count--;
                }
            }
            
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if(count==0)
                {
                    return true;
                }
                if(mp.find(s[i])!=mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                    {
                        count++;
                    }
                }
                i++;
                j++;
            
            }
        }
        return false;
    }
};