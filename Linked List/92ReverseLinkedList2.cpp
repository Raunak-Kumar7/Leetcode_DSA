ListNode *reverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == right)
        return head; // single element
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *temp = dummy;
    int i = 1;
    while (i + 1 <= left)
    {
        temp = temp->next;
        i++;
    }
    // now temp stands one node before the left node

    ListNode *temp2 = dummy;
    int j = 0;
    while (j != right)
    {
        temp2 = temp2->next;
        j++;
    }
    // now temp2 stands at right node

    ListNode *r = temp2->next;
    temp2->next = nullptr;
    // connection broken to right half
    // now we need to reverse till end starting from temp->next

    ListNode *newLeft = reverse(temp->next);

    ListNode *t = newLeft;
    while (t->next != nullptr)
    {
        t = t->next;
    }

    // re-establishing connections
    t->next = r;
    temp->next = newLeft;

    return dummy->next;
}