#include <bits/stdc++.h> 
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
    void markEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
    
};
class Trie {
private: Node* root; 
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++) {
            if(!node->isPresent(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->markEnd();
    }

    bool checkIfAllPrefixExists(string s)
    {
        Node* node = root; 
        for(int i=0;i<s.size();i++)
        {
            if(node->isPresent(s[i]))
            {
                node = node->get(s[i]); //true is marked on the next node
                if(node->isEnd()==false)
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;

    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto it:a)
    {
        trie.insert(it);
    } 
    string ans ="";
    int mx =0;
    for(auto it:a)
    {
        if(trie.checkIfAllPrefixExists(it))
        {
            if(it.size()>mx)
            {
                ans = it;
                mx = it.size();
            }
            else if(it.size()==mx && it<ans) //return lexicographically smaller
            {
                ans = it;
                mx = it.size();
            }
        }
    }
    if(ans=="")
        return "None";
    return ans;
}