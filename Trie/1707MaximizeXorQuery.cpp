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
    //Code above this is same as 421
    static bool comp(vector<int> &A, vector<int> &B)
    {
        return A[1]<B[1]; //Ascending Order. True means it is in correct position
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        
        Trie trie;
        sort(nums.begin(),nums.end());//to have nums elements keep comin in sorted order
        int n = nums.size();
        int q = queries.size();
        for(int i=0;i<q;i++)
        {
            queries[i].push_back(i); //To store index bcz answer should be in this order
        }
        vector<int> ans(q,-1);
        sort(queries.begin(),queries.end(),comp);//sorted according to m values
        int x=0;
        for(int i=0;i<q;i++)
        {
            int m = queries[i][1];
            while(nums[x]<=m && x<n)
            {
                trie.insert(nums[x]);
                x++;
            }
            if(m<nums[0]) //Empty Trie
                continue;
            ans[queries[i][2]] = trie.getMax(queries[i][0]);
        }
        return ans;
    }
};