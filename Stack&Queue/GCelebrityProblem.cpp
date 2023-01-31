//ALSO CHECK THE GRAPH BASED QUESTION

//Function to find if there is a celebrity in the party or not.
//T.C. O(n^2) S.C. O(1)
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //celebrity will be a person whose row is full of 0s 
        //and at that columnit is all ones
        vector<int> candidate;
        for(int i=0;i<n;i++)
        {
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true) //means all 0s
                candidate.push_back(i);
        }
        for(int i=0;i<candidate.size();i++)
        {
            int cand = candidate[i];
            bool flag = true;
            for(int j=0;j<n;j++)
            {
                if(M[j][cand]==0 && j!=cand)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                return cand;
        }
        return -1;
    }


//Optimised Approach
//O(n) T.C. O(N) S.C.
int celebrity(vector<vector<int> >& M, int n) 
    {
        //O(n) Code using Stack 
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>=2)
        {
            int t1 = st.top();
            st.pop();
            int t2 = st.top();
            st.pop();
            if(M[t1][t2]==1) //means t1 knows t2 -> t1 is not celebrity
            {
                st.push(t2);
            }
            else //means t1 does not know t2 --> t2 is not celebrity
            {
                st.push(t1);
            }
            
        }
        //now what is left is a candidate for celebrity //check if its entire row is 0 and entire column = 1 except self
        bool flag = true;
        int c = st.top();
        for(int i=0;i<n;i++)
        {
            if(M[c][i]==1)
            {
                flag = false;
                break;
            }
            if(M[i][c]==0 && i!=c)
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
            return -1;
        return c;
        // code here 
    }