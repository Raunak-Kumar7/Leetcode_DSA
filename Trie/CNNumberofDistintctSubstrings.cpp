struct Node{
  Node *links[26];
    bool flag = false;
    //Functions
    bool isPresent(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
};
int countDistinctSubstrings(string &word)
{
    //    Write your code here.
    Node* root=new Node();
    int cnt=0;
    for(int i=0;i<word.size();i++) //start of substring
    {
        Node* node = root;
        for(int j=i;j<word.size();j++) {
          if (!node->isPresent(word[j])) {
              cnt++;
            node->put(word[j], new Node());
          }
          node = node->get(word[j]);
        }
    }
    return cnt+1;
}