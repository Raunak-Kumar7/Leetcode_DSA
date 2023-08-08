// Using DSU
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // S1- each row will be indentified  with its index number

        // S2 - keep adding in a mao and union by dsu
        int n = accounts.size();
        unordered_map<int, string> names;
        for (int i = 0; i < n; i++)
        {
            names[i] = accounts[i][0];
        }
        unordered_map<string, int> mp;

        DisjointSet DSU(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++) // emails
            {
                if (mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    DSU.unionByRank(i, mp[accounts[i][j]]); // joing to single component
                }
            }
        }
        // create for all nodes //stores only mails
        vector<vector<string>> tempans(n);
        for (auto it : mp)
        {
            string mail = it.first;
            int p = DSU.findUPar(it.second);
            tempans[p].push_back(mail);
        }
        // store final ans by adding names first and sorting the emails
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (tempans[i].size() == 0)
                continue;

            vector<string> temp;
            temp.push_back(accounts[i][0]);             // name
            sort(tempans[i].begin(), tempans[i].end()); // want emails in sorted order

            temp.insert(temp.end(), tempans[i].begin(), tempans[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};