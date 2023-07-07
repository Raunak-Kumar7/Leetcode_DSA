// Similar to Maximum Sum Combinations Heap {val,{nums 1 index, nums2 index}}
// here nums1 and nums2 are of diff size
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // min heap
    set<pair<int, int>> st;                                                                                              // to prevent dupliates
    vector<vector<int>> ans;

    pq.push({nums1[0] + nums2[0], {0, 0}});
    st.insert({0, 0});
    if (k > 1ll * n1 * n2)
        k = n1 * n2;
    while (k--)
    {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();

        int l = p.second.first;
        int r = p.second.second;
        ans.push_back({nums1[l], nums2[r]});

        if (l + 1 < n1 && st.find({l + 1, r}) == st.end())
        {
            pq.push({nums1[l + 1] + nums2[r], {l + 1, r}});
            st.insert({l + 1, r});
        }
        if (r + 1 < n2 && st.find({l, r + 1}) == st.end())
        {
            pq.push({nums1[l] + nums2[r + 1], {l, r + 1}});
            st.insert({l, r + 1});
        }
    }
    return ans;
}