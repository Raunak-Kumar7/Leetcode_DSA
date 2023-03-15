//Brute force : Store in vector and check O(n) O(n)
    bool isPalindrome(ListNode* head) {
        vector<int> a;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            a.push_back(temp->val);
            temp = temp->next;
        }
        int n = a.size();
        for(int i=0;i<=n/2;i++)
        {
            if(a[i]!=a[n-i-1])
                return false;
        }
        return true;
    }


    //Aprroach O(2n) O(1) space
    //reverse the first half and again traverse
    //To get First half we need to first find the mid using Slow Fast Approach
    