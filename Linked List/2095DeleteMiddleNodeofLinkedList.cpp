//Problem is similar to find the middle in the linked list 
    //Slow fast pointer technique
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == nullptr) return nullptr; //single node in LL
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next->next!=nullptr && fast->next->next->next!=nullptr) //We need to stop 1 position before mid
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = slow->next->next;
        return head;
    }