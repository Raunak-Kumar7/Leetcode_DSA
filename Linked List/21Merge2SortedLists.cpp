    //Merge sort --> Merge Function
    ListNode* merge(ListNode* list1, ListNode* list2) //here list 1 has smaller starting element
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            if(temp1->val < temp2->val)
            {
                dummy->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                dummy->next = temp2;
                temp2 = temp2->next;
            }
            dummy = dummy->next;
        }
        if(temp1!=nullptr) 
            dummy->next = temp1;
        if(temp2!=nullptr)
            dummy->next = temp2;
        
        if(list1->val < list2->val) 
            return list1;
        else 
            return list2;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //Without Creating a new List O(1) Space
        if(list1==nullptr)
            return list2;
        if(list2==nullptr)
            return list1;
        return merge(list1,list2);
    }