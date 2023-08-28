ListNode* reverse(ListNode* head) {
        ListNode* dummy = nullptr;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        bool flag = false;   
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while(temp)
        {
            ListNode* t1 = temp;
            int cnt = 1;
            while(cnt<k && t1->next)
            {
                t1 = t1->next;
                cnt++;
            }
            if(cnt<k)
            {
                prev->next = temp;
                break;
            }
            ListNode* t2 = t1->next;
            t1->next = nullptr;
            
            ListNode* t3 = reverse(temp);
            if(prev)
            {
                prev->next = t3;
            }
            if(!flag)
            {
                dummy = t3;
                flag = true;
            }
            prev = temp;
            temp->next = t2;
            temp = temp->next;
        }
        return dummy;
    }