    //reverse the list from middle then take pair sums
    ListNode* reverse(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* temp = head;
        ListNode* prev =nullptr;
        while(temp!=nullptr)
        {
            temp=temp->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        slow = head;
        fast = head;
        while(fast->next->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;
        int maxi = INT_MIN;
        while(slow!=nullptr)
        {
            maxi = max(maxi, slow->val+head->val);
            slow = slow->next;
            head = head->next;
        }
        return maxi;
        
    }