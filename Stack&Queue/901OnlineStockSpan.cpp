 //For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
//Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
 
 //   https://leetcode.com/problems/online-stock-span/discuss/640358/JAVA-Solution-With-visualization-and-easy-explained!
    stack<pair<int,int>> s; //to store value, cnt of lesser than before
    StockSpanner() {
        
    }
    
    int next(int price) {
        int cnt = 1;
        while(!s.empty() && s.top().first<=price)
        {
            cnt+=s.top().second;
            s.pop();
        }
        s.push({price,cnt});
        return cnt;
    }
};