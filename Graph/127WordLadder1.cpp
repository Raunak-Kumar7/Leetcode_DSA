// put the dictionary in set for quick search
// Using BFS
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    set<string> st;
    for (auto it : wordList)
    {
        st.insert(it);
    }

    queue<pair<string, int>> q; //{word,dist/level}
    q.push({beginWord, 1});
    if (st.find(beginWord) != st.end())
        st.erase(beginWord);
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            pair<string, int> n = q.front();
            q.pop();
            if (n.first == endWord)
                return n.second;

            string s = n.first;
            string temp = s;
            int len = s.size();
            for (int i = 0; i < len; i++) // changing char on ith index
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    s[i] = ch;
                    if (st.find(s) != st.end())
                    {
                        q.push({s, n.second + 1});
                        st.erase(s); // marking visited
                    }
                }
                s = temp; // reset because only 1 change is allowed
            }
            countNodes--;
        }
    }
    return 0;
}