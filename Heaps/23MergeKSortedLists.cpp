    //Total Brute force is to solve exactly like arrays and again creating a new lists
    //Approach 1: like Merge Sorted Arrays Min Heap {value,currptr} --> By changing Pointers //We actually dont need the idx poointer here
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=nullptr)
                pq.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        while(!pq.empty())
        {
            pair<int,ListNode*> x = pq.top();
            pq.pop();
            ListNode* temp = x.second;
            dummy->next = x.second;
            dummy = dummy->next;
            if(temp->next!=nullptr)
            {
                temp = temp->next;
                pq.push({temp->val,temp});
            }
        }
        return ans->next;
    }