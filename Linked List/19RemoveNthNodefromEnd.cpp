    //Approach 1: count number of nodes N, delete now we have to delete N-n+1th node
    //So we stand at N-n
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N=0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            N++;
            temp = temp->next;
        }
        if(n==N) //delete first node
            return head->next;
        temp = head;
        int x = N-n;
        while(--x)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }


    //Approach 2: Slow Fast Pointer Aprroach (slight twisted) (Actually 2 pointer)
    //We need the slow pointer to reach the N-nth node when the fast node reaches end 
    //So a CONSTANT gap of n should be maintained between slow and fast ptrs
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++)
            fast = fast->next;
        //gap of n is made
        while(fast!=nullptr && fast->next!=nullptr) //stop 1 step before to delete
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast == nullptr) //means delete 1st node
            return slow->next;
        slow->next = slow->next->next;
        return head;
    }