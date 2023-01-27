 //O(n) , O(1) Solution 
    //Without creating an array to store maxtillnow
    //We can simply use a variable maxtillnow
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxtillnow = prices[n-1];
        int profit = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(maxtillnow-prices[i]>profit)
            {
                profit = maxtillnow-prices[i];
            }
            if(prices[i]>maxtillnow)
            {
                maxtillnow = prices[i];
            }
        }
        return profit;
    }