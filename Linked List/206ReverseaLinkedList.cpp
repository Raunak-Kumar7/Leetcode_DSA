//Approach 1 : Iterative Approach
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) 
            return head;
        
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* n = head->next;
        
        while(temp->next!=nullptr)
        {
            temp->next = prev;
            prev = temp;
            temp = n;
            n = n->next;
        }
        temp->next = prev;
        return temp;
    }


