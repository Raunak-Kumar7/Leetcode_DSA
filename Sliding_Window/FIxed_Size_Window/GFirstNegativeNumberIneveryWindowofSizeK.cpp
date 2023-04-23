///QUEUE use [Nice Concept of storing useful numbers in queue/list]
#define ll long long int
vector<long long> printFirstNegativeInteger(long long int a[],long long int n, long long int k) {
    int i=0;
    int j=0;
    vector<ll> ans;
    queue<pair<ll,ll>> q; //{negative number, index}to keep negative numbers as they are coming and remove when i crosses it
    while(j<n)
    {
        if(a[j]<0)
            q.push({a[j],j});
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            if(!q.empty())
                ans.push_back(q.front().first);
            else
                ans.push_back(0); //if no negative element in window
            if(!q.empty() && q.front().second == i)//only 1 element is popped as window slides by 1
                q.pop();
            i++;
            j++;
        }
    }
    return ans;
}