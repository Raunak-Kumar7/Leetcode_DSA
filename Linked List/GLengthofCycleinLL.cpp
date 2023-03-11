//Approach : Slow Fast Pointer Approach
//if cycle is found iterate 1 pointer and keep 1 fixed
int countNodesinLoop(struct Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    while(fast!=nullptr && fast->next!=nullptr) //write fast!=nullptr FIRST
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) //cycle found
        {
            int cnt = 1;
            slow = slow->next; //keeping fast fixed
            while(slow!=fast)
            {
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0; //no cycle found
}