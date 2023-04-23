//using res as a stack(concept: VECTOR AS A STACK)


    string removeStars(string s) {
        string res = "";
        for(auto i:s)
        {
            if(i!='*')
                res.push_back(i); 
            else
                res.pop_back();
        }
        return res;
    }


// 844. Backspace String Compare
// 1047. Remove All Adjacent Duplicates In String
// 1209. Remove All Adjacent Duplicates in String II -- Medium
// 1544. Make The String Great