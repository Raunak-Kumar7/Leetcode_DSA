struct Node{
  Node *links[2];
    bool flag = false;
    //Functions
    bool isPresent(int c){
        return (links[c]!=NULL);
    }
    void put(int c, Node* node){
        links[c]=node;
    }
    Node* get(int c){
        return links[c];
    }
    void markEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};

class Trie 
{
private: Node* root; 
public:
    Trie() 
    {
        root = new Node();
    }
    void insert(int num) { //insertion begins from MSB
        Node* node=root;
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1; //to extract the ith bit, &1 to check if 0 or 1 IMPORTANT
            if(!node->isPresent(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
        }
        node->markEnd();
    }
    int getMax(int num){
        Node* node = root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit = (num >> i) & 1;
            if(node->isPresent(!bit)){
                ans = ans | (1<<i);
                node = node->get(!bit);
            }
            else{ //bcz if opposite bit not found then xor =0 , which is already 0 by default so no need to do the same
                node = node->get(bit);
            } 
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto it: nums)
        {
            trie.insert(it);
        }
        int maxXor =0;
        for(auto it:nums)
        {
            maxXor = max(maxXor,trie.getMax(it));
        }
        return maxXor;
    }
};