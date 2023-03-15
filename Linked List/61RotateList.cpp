    int countNodes(ListNode* head)
    {
        int x = 0;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            x++;
            temp = temp->next;
        }
        return x;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //reach to n-kth node , connect tail to head break the link from previous node
        int n = countNodes(head);
        if(n==0) return head; //edge case bcz cant take % when n=0
        k = k%n;  
        if(k==0) return head;
        //we have to stop 1 before k
        //n-k-1
        ListNode* temp = head;
        int x = n-k-1;
        while(x>0&&temp!=nullptr)
        {
            temp = temp->next;
            x--;
        }
        ListNode* nn = temp->next;
        ListNode* ans = nn;
        temp->next = nullptr;
        while(nn->next!=nullptr)
            nn=nn->next;
        nn->next = head;
        return ans;
    }