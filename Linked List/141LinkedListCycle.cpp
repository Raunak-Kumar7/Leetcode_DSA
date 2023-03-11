//Slow Fast Pointer (if any time both become equal)
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr) //always write fast!=nullptr FIRST in slow fast approach
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
    }