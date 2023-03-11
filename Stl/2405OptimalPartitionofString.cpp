   //To make it optimal, Take in a substring till its possible
    
    //Resize Function
//     The second parameter of resize specifies the new size of the vector after resizing.

// When you call a.resize(26, 0), you are telling the vector to resize to a size of 26 elements. If the current size of the vector is less than 26, new elements will be added to the end of the vector, and these new elements will be initialized to their default value, which in this case is 0.

// On the other hand, if the current size of the vector is greater than or equal to 26, the excess elements will be removed from the vector, and the remaining elements will retain their values.

// In summary, the second parameter of resize specifies the new size of the vector after resizing, and any new elements added to the vector will be initialized to their default value. However, the existing elements in the vector will retain their values.




    int partitionString(string s) {

        vector<int> a(26,0);
        int n = s.size();
        int cnt = 1;
        for(int i=0;i<n;i++)
        {
            if(a[s[i]-'a']==1)
            {
                fill(a.begin(),a.end(),0);
                //a.resize(26,0);
                cnt++;
            }
            a[s[i]-'a']++;
        }
        return cnt;
        
    }