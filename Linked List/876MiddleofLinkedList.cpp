    //Aproach 1: Count number of nodes, then traverse to n/2th node and return t.c.O(2n)
    
    //Fast And Slow Pointer Approach
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        //Write the condition for even first bcz if fast is nullptr then fast -> next doesnt exist
        while(fast != nullptr && fast->next!=nullptr ) //for odd number of nodes -> fast->next!=nullptr
                                                       // for even number of nodes-> fast !=nullptr
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }