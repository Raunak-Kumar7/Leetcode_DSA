class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int v;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums)
        {
            pq.push(it);
            if(pq.size()>k)
                pq.pop();
        }
        v =k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>v)
            pq.pop();
        return pq.top();
    }
};