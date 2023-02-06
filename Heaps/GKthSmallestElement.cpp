//Max Heap Solution
    // T.C O(n) S.C O(k)
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        for(int i=0;i<r-l+1;i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }