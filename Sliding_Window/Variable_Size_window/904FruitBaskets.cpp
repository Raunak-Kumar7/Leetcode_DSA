//Variable size sliding window
    //max length of window with 2 unique numbers
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        int i=0,j=0;
        int n = fruits.size();
        while(j<n)
        {
            mp[fruits[j]]++;
            if(mp.size()<=2) //Updating value even if there is 1 unique fruit because there can be an array [1,1,1,1,1]
            {
                maxi = max(maxi,j-i+1);
            }
            else if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                        mp.erase(fruits[i]);
                    i++;
                }
            }
            j++;
        }
        return maxi;
    }