// Merge 2 at a time
Node *mergeSortedLL(Node *a, Node *b)
{
    if (b->data < a->data)
        return mergeSortedLL(b, a);

    Node *dummy = new Node(-1);
    Node *ans = dummy;
    while (a && b)
    {
        if (a->data < b->data)
        {
            dummy->bottom = a;
            a = a->bottom;
            dummy = dummy->bottom;
        }
        else
        {
            dummy->bottom = b;
            b = b->bottom;
            dummy = dummy->bottom;
        }
    }
    if (a)
        dummy->bottom = a;
    if (b)
        dummy->bottom = b;

    return ans->bottom;
}
Node *flatten(Node *root)
{
    if (root == nullptr || root->next == nullptr)
        return root;

    Node *curr = root;
    Node *nxt = root->next;
    while (nxt)
    {
        Node *tmp = nxt->next;
        curr = mergeSortedLL(curr, nxt);
        nxt = tmp;
    }
    return curr;
}

//------------------

/// We can also write the flatten func recursively

Node *flatten(Node *root)
{
    // Your code here
    if (root == nullptr || root->next == nullptr) // in case 0 or only 1 LL is left directly return head, no need to flatten or merge
        return root;
    root->next = flatten(root->next); // Start merging from last 2 LL recursively
    root = merge(root, root->next);
    return root;
}