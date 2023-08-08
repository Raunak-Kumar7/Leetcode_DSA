// BFS
int getImportance(vector<Employee *> employees, int id)
{
    int total = 0;
    unordered_map<int, int> mp; //{id,index}
    int i = 0;
    for (auto it : employees)
    {
        mp[it->id] = i;
        i++;
    }

    queue<int> q;
    q.push(id);
    while (!q.empty())
    {
        int countNodes = q.size();
        while (countNodes > 0)
        {
            int id = q.front();
            q.pop();

            total += employees[mp[id]]->importance;
            for (auto j : employees[mp[id]]->subordinates)
                q.push(j);

            countNodes--;
        }
    }
    return total;
}