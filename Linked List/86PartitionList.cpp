    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* temp = dummy;
        ListNode* tail = head;
        
        while(tail->next)
        {
            tail = tail->next;
        }
        ListNode* tailfix = tail;
        
        while(temp->next!=tailfix) //no need to remove the last node even if its >= x in loop --> else infinite loop
        {
            if(temp->next->val >= x)
            {
                ListNode* rmv = temp->next;
                temp->next = temp->next->next;
                tail->next = rmv;
                rmv->next = nullptr;
                tail = tail->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        //if last node >=x replace it here
        if(temp->next->val >= x && temp->next->next !=nullptr) //should not be a single node ll
        {
            ListNode* rmv = temp->next;
            temp->next = temp->next->next;
            tail->next = rmv;
            rmv->next = nullptr;
        }
        return dummy->next;
    }