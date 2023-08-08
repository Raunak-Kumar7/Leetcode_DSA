// Brute force : Store in vector and check O(n) O(n)
bool isPalindrome(ListNode *head)
{
    vector<int> a;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        a.push_back(temp->val);
        temp = temp->next;
    }
    int n = a.size();
    for (int i = 0; i <= n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
            return false;
    }
    return true;
}

// Aprroach O(2n) O(1) space
// reverse the first half and again traverse
// To get First half we need to first find the mid using Slow Fast Approach

// Brute : store in second half of ll and check palindrome O(N) O(N/2)

// Optimal : reverse the second half and compare the 2 lists
// APPROACH :
// STEP1 : FUNCTION TO RETURN MID --> FOR EVEN .->.->(.)->. , FOR ODD .->.->.->(.)->.
// STEP2 : REVERSE THE SECOND HALF
// STEP3: COMPARE BOTH THE HALVES
ListNode *mid(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast == nullptr) // even length ll
        return slow;
    else // odd length ll
        return slow->next;
}
ListNode *reverse(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *nxt = head->next;
    while (nxt != nullptr)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
    }
    curr->next = prev;
    return curr;
}
bool isPalindrome(ListNode *head)
{
    ListNode *head2 = reverse(mid(head));
    ListNode *temp1 = head;
    ListNode *temp2 = head2;
    while (temp2 != nullptr)
    {
        if (temp1->val != temp2->val)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
