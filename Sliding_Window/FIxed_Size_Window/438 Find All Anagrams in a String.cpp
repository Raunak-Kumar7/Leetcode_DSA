// Based on Count Occurence of Anagrams

//Q Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// https://leetcode.com/problems/find-all-anagrams-in-a-string/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
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
                    ans.push_back(i);
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
        return ans;
    }
};