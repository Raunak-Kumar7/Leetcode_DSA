    string arrangeWords(string text) {
        priority_queue<pair<int,pair<int,string>>, vector<pair<int,pair<int,string>>>,greater<pair<int,pair<int,string>>>> pq; //{size,wordindex}
        string ans = "";
        text = text + " ";
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        int n = text.size();
        string w = "";
        int wc = 0;
        for(int i=0;i<n;i++)
        {
            char c = text[i];
            if(c!=' ')
                w+=c;
            else
            {
                pq.push({w.size(),{wc,w}});
                wc++;
                w="";
            }
        }
        while(!pq.empty())
        {
            ans+=pq.top().second.second + " ";
            pq.pop();
        }
        ans[0] = ans[0] -32; //capital
        string fans = ans.substr(0,ans.size()-1); //immutable
        return fans;
    }