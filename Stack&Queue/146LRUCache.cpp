class LRUCache {
public:
    
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int k, int v)
        {
            key = k;
            val = v;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int,node*> m;
    
    void addNode(node* newnode)
    {
        node* temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        newnode->next = temp;
        temp->prev = newnode;
    }
    void deleteNode(node* delnode)
    {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
        //connect head and tail
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* res = m[key]; //write this should not access again and again 
            int ans = res->val;
            deleteNode(res);
            addNode(res);
            m.erase(key);
            m[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* res = m[key];
            deleteNode(res);            
            m.erase(key);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        m[key] = head->next;
    }
};