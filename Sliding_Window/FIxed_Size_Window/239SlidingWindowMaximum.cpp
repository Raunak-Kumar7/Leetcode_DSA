// Points To remember:
// 1. Fixed sliding window approach
// 2. Use list/dqueue to remove elements if we get a bigger element as we did in nge i.e.
// REMOVE TILL ELEMENTS IN THE QUEUE ARE GREATER THAN CURRENT ELEMENT
// For every window the max element will be alwyas the front element---------
//{value,index}
// For every window the max element will be alwyas the front element
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    list<pair<int, int>> ls; //{value,index}
    int i = 0;
    int j = 0;
    while (j < n)
    {
        while (!ls.empty() && ls.back().first <= nums[j])
        {
            ls.pop_back();
        }
        ls.push_back({nums[j], j});

        if (j - i + 1 < k)
            j++;
        else if (j - i + 1 == k)
        {
            ans.push_back(ls.front().first);
            if (ls.front().second == i)
                ls.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}