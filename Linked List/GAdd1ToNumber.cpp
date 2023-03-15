Node* reverse(Node* head)
    {
        if(head==nullptr || head->next==nullptr) return head;
        Node* prev = nullptr;
        Node* curr = head;
        while(curr!=nullptr)
        {
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        //Step 1: reverse the LL then add 1 then again reverse the ll
        Node* back = reverse(head);
        Node* temp = back;
        int carry = 1;
        Node* y;
        while(temp!=nullptr)
        {
            int x = temp->data;
            temp->data = (x+1)%10;
            carry = (x+1)/10;
            if(carry==0) break;
            y=temp;
            temp = temp->next;
        }
        if(carry!=0)
        {
            Node* n = new Node(carry);
            y->next = n;
        }
        
        Node* h = reverse(back);
        return h;
    }