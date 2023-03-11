    //Slow Fast Pointer Approach
    //If cycle is detected we need to put slow ptr back to head and then again traverse(but now fast by 1)
    //Observations:
    //Case1 : If the tail connects the head i.e. entire list is a cycle -->then slow and fast always meet at head
    //Case2 : If tail connects somewhere in the middle, then the number of moves to the beginning of the cycle from the head ===== number of moves from the matching position of slow and fast to the starting postion of cycle

    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr) //always write fast!=nullptr FIRST
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) //Means cycle is detected
            {
                //Now put back slow to head and again move both slow fast but BOTH 1 BY 1
                slow = head;
                while(true)
                {
                    if(slow==fast)
                        return slow;
                    slow = slow->next;
                    fast = fast->next; ///Also by 1
                }//number of moves from head = number of moves from matching point
                    
            }
        }
        return nullptr;
    }