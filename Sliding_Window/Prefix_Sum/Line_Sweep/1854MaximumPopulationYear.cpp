    //Brute Force do basic preifx sum, by going at every index
    
    //The question is Easy because it has lesser constraints
    //But with higher constraints brute force will give TLE
    
    //Line Sweep technique(intervals) (Prefix Sum)
    int maximumPopulation(vector<vector<int>>& logs) {
        //Here death year is not counted for no of people so we do prefix[right]++
        int n = logs.size();
        //max value of deathi = 2050 so we have to go till death
        vector<int> prefix(2051,0);
        for(int i=0;i<n;i++)
        {
            int l = logs[i][0];
            int r = logs[i][1];
            prefix[l]++;
            prefix[r]--;
        }
        //Now we create the prefix array
        int maxi = 0;
        int ans;
        // for(int i = 1966;i<=2051;i++)
        //     cout<<prefix[i]<<" ";
        for(int i=1;i<2051;i++)
        {
            prefix[i] = prefix[i-1] + prefix[i];
            if(prefix[i]>maxi) //first year with max so not >=
            {
                maxi = prefix[i];
                ans = i; //return year
            }
        }
        
        return ans;
    }