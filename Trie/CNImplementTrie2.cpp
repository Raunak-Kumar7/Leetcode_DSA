#include <bits/stdc++.h> 
struct Node{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
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
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    
};
class Trie{
    private: Node* root;
    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here. 
        //Search code
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i]) ){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->cntPrefix;
    }
    //In erase function we are not deleting the Node we are just decreasing the count
    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->isPresent(word[i]))
            {
                return; 
            }
            node = node->get(word[i]);
            node->cntPrefix--;
        }
        node->cntEndWith--;
    }
};