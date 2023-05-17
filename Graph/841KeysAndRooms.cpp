    //BFS
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n,0);
        queue<int> q;
        for(auto it:rooms[0])
        {
            q.push(it);
        }
        visited[0] = 1;
        while(!q.empty())
        {
            int countNodes = q.size();
            while(countNodes>0)
            {
                int node = q.front();
                q.pop();
                visited[node] = 1;
                for(auto it:rooms[node])
                {
                    if(!visited[it]) //one room may have multiple keys in different rooms no need to pick again and again
                        q.push(it);
                }
                countNodes--;
            }
        }
        for(auto it:visited)
        {
            if(it==0)
                return false;
        }
        return true;
    }


//Do DFS