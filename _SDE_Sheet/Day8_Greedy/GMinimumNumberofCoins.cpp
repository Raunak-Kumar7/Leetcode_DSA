    //Greedy always doesn't work 
    //DP Solution is General --> coin change (lc)
    vector<int> minPartition(int N)
    {
        
        vector<int> coin{1,2,5,10,20,50,100,200,500,2000}; //infinite supply
        int n = coin.size();
        reverse(coin.begin(),coin.end());
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(N>=coin[i])
            {
                int c = N/coin[i];
                N -= c*coin[i];
                while(c--)
                {
                    ans.push_back(coin[i]);
                }
            }
            else if(N<=0)
                break;
        }
        return ans;
    }