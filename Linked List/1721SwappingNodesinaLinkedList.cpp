    //Method 1
    int count(ListNode* head)
    {
        int cnt = 0;
        while(head!=nullptr)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* f = head;
        ListNode* s = head;
        int n = count(head);
        int i = 1;
        while(i<k)
        {
            f = f->next;
            i++;
        }
        i = 1;
        while(i<n-k+1)
        {
            s = s->next;
            i++;
        }
        swap(f->val,s->val);
        return head;
    }



// (BETTER APPROACH)
        //2 pointer
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* f = head;
        ListNode* e = head;
        ListNode* s = head;
        int cnt = 1;
        while(cnt<k)
        {
            f = f->next;
            e = e->next;
            cnt++;
        }
        while(f->next!=nullptr)
        {
            f = f->next;
            s = s->next;
        }
        //Swap s and e
        swap(s->val,e->val);
        return head;
    }