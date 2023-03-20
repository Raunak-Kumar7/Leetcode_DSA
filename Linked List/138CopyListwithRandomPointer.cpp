    //2 Approaches:
    //Approach 1 : using hashmap T.C. O(2n) S.C. O(n)
    //Approach 2 : S.C. O(1)
    Node* copyRandomList(Node* head) {
        //Using Approach 1
        unordered_map<Node*,Node*> mp;
        Node* temp = head;
        //S1: create new nodes corresponding to original nodes without creating any links
        while(temp!=nullptr)
        {
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }
        //S2: creating links
        temp = head;
        while(temp!=nullptr)
        {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }

//Revise 2nd approach, code

//Method is similar to LRU cache where in dll we inserted in between
Node* copyRandomList(Node* head) {
        //Approach 2: using O(1) Space
        if(head==nullptr) 
            return nullptr;
    
        //Step 1: Create newNodes and insert in between original LL
        Node* temp = head;
        while(temp!=nullptr)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        
        //Step 2: Create random Links in NewNodes
        temp = head;
        while(temp!=nullptr)
        {
            if(temp->random == nullptr) // in case temps random is nullptr so its next wont exist
            {
                temp->next->random = temp->random;
            }
            else
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        //Step 3: Get new LL and original LL back
        temp = head; //to point original LL
        Node* dummy = new Node(-1); // to point new LL
        dummy->next = temp->next; //1
        Node* temp2 = dummy->next; //to iterate over new LL
        Node* front = temp->next->next;
        while(front!=nullptr)
        {
            temp->next = front;//2,3
            temp = front;//4
            front = front->next->next;//5
            temp2->next = temp->next;//6,7
            temp2 = temp2->next;
        }
        temp->next = front;//pointing last node of original LL back to nullptr
        return dummy->next;
    }