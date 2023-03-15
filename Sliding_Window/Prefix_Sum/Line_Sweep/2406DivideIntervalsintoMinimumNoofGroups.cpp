 //Based On Line Sweep (prefix Sum)
    //If we go and do +1 at every index for every range it will give TLE, 
    //So we do A[Left]++ and do A[right+1]-- // which will create the prefix array sum(without going to each index)
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> prefix(1e6+2,0); //We will have to go till right+1
        for(int i=0;i<n;i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            prefix[l]++;
            prefix[r+1]--;
        }
        //Now we form the prefix array
        int maxi = 1;
        for(int i = 1;i<1e6+2;i++)
        {
            prefix[i] = prefix[i-1] + prefix[i];
            maxi = max(maxi,prefix[i]);
        }
        return maxi;
    }