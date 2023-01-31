class LFUCache {
    public:
    class node{
        public:
        int key;
        int val;
        int cnt;
        node* next;
        node* prev;
        node(int k, int v)
        {
            cnt = 1;
            key = k;
            val = v;
        }
    };
    struct List {
        int size;
        node* head;
        node* tail;
        List()
        {
            size = 0;
            head = new node(-1,-1);
            tail = new node(-1,-1);
            head->next = tail;
            tail->prev = head;
        }
    void addFront(node* newnode)
    {
        node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
        size++;
    }
    void removeNode(node* delnode)
    {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
        size--;
    }
};
    
    map<int, node*> keyNode;
    map<int, List*> freqList;
    int maxSize;
    int currSize;
    int minFreq;
    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }
    void updateFreqListMap(node* node)
    {
        keyNode.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqList[node->cnt]->size == 0){
            minFreq++;
        }
        List* nextHigherFreqList = new List();
        if(freqList.find(node->cnt + 1)!= freqList.end())
        {
            nextHigherFreqList = freqList[node->cnt +1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqList[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            node* res = keyNode[key];
            int ans = res->val;
            updateFreqListMap(res);
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSize==0){
            return;
        }
        if(keyNode.find(key)!=keyNode.end())
        {
            node* res = keyNode[key];
            res->val = value;
            updateFreqListMap(res);
        }
        else
        {
            if(currSize == maxSize)
            {
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List* listFreq = new List();
            if(freqList.find(minFreq)!=freqList.end())
            {
                listFreq = freqList[minFreq];
            }
            node* n = new node(key,value);
            listFreq->addFront(n);
            keyNode[key] = n;
            freqList[minFreq] = listFreq;
        }
    }
};

