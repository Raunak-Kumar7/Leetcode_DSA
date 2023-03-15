//T.C. O(max(n,m)+1)
    //S.C. O(max(n,m)+1)
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ans = dummy;
        int carry = 0;
        while(l1!=nullptr && l2!=nullptr)
        {
            
            int x = l1->val + l2->val + carry;
            ListNode* temp = new ListNode(x%10);
            dummy->next = temp;
            carry = x/10;
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }
        while(l1!=nullptr)
        {
            int x = l1->val + carry;
            ListNode* temp = new ListNode(x%10);
            dummy->next = temp;
            carry = x/10;
            l1 = l1->next;
            dummy = dummy->next;
        }
        while(l2!=nullptr)
        {
            int x = l2->val + carry;
            ListNode* temp = new ListNode(x%10);
            dummy->next = temp;
            carry = x/10;
            l2 = l2->next;
            dummy = dummy->next;
        }
        while(carry!=0)
        {
            ListNode* temp = new ListNode(carry%10);
            carry/=10;
            dummy->next = temp;
            dummy = dummy->next;
        }
        return ans->next;
    }