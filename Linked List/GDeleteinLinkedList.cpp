Node* deleteNode(Node *head,int x)
{
    //Your code here
    if(x==1) //Delete at head
        return head->next;
    Node* temp = head;
    Node* prev = NULL;
    x--;
    while(temp->next!=NULL && x>0)
    {
        prev = temp;
        temp = temp->next;
        x--;
    }
    //temp has the node to be deleted
    prev->next = temp->next; //skipped temp
    delete temp; //optional
    return head;
}