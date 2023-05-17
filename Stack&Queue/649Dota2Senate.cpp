//Read other approaches from lc solution section

//people will keep banning others until only 1 party is left 
    //will ban the first person of other party found 
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> q1;
        queue<int> q2;
        for(int i=0;i<n;i++)
        {
            if(senate[i]=='R')
                q1.push(i);
            else
                q2.push(i);
        }
        while(!q1.empty() && !q2.empty())
        {
            int a = q1.front();
            q1.pop();
            int b = q2.front();
            q2.pop();
            if(a<b)
                q1.push(a+n); //if we dont add n, team at index 0 always wins
            else
                q2.push(b+n);
        }
        if(q1.size()>0)
            return "Radiant";
        else
            return "Dire";
    }