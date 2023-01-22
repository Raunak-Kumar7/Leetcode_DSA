//same as 208 Search function except a . can exist which means any character
bool search(Node* node,string word)
    {
        for(int i = 0;i<word.size();i++)
        {
            if(word[i]=='.') //Special Case: if we encounter a dot then we need to check all the characters(any can come), when we find a char we call search function with the remaining word
            {
                for(int j = 0;j<26;j++)
                {
                    if(node->links[j]!=NULL)
                    {
                        if(search(node->links[j],word.substr(i+1))){ //check if the remaining string matches after it
                            return true;
                        }
                    }
                }
                return false;
            }
            if(!node->isPresent(word[i])){
                return false;
            }
            else
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool search(string word) {
        Node* node = root;
        return search(node,word);
    }