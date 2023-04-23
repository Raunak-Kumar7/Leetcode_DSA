    // (Similar to 2449/2541)
    
    //to have equal in both baskets --> total freq would be even
    //Instead of using 2 maps we can use 1 map and +basket1 -basket2
    //if equal its frequency would be 0
    
    //To have min ans we swap min with max value
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int,int> mp;
        int n = basket1.size();
        for(int i=0;i<n;i++)
        {
            mp[basket1[i]]++;
            mp[basket2[i]]--;
        }
        //if any frequency is odd ---> impossible
        //further --> we convert each freq as freq/2 to get number of operations --> summation should be 0 of netdiff
        // add all operations
        //again traverse map add key to ans until operations left
        long long netdiff = 0;
        long long operations = 0;
        long long cost = 0;
        for(auto it:mp)
        {
            if(((int)abs(it.second)%2)==1) return -1;
            netdiff += it.second;
            if(it.second > 0) operations +=it.second/2;
        }
        if(netdiff!=0) return -1; //unequally distributed
        for(auto it:mp)
        {
            long long cnt = (int)abs(it.second)/2 <= operations ? (int)abs(it.second)/2 : operations;
            cost+=min(it.first, begin(mp)->first * 2)*cnt; //This edge case i was missing // that even though the minimum element has same frequency in both the arrays we can still use it to have minimum swaps //seen from votrubac
            // Note that it may be cheaper to do two swaps with the cheapest fruit, that one swap with the current one.


            operations-=cnt;
            if(operations==0) break;
        }
        return cost;
        
    }


// what is begin(m)->first*2 and its need??



//     it's like using it like temp variable for swaping two values;
// a=[2,5,5]; b=[2,6,6];
// swap a's 2 with b's 6 now u have a=[6,5,5] & b=[2,2,6]
// and now swap b's 2 with a's 5 now a=[6,2,5] & b=[2,5,6];
// and the cost is 2*2 which is smaller than 5 if we directly swap 5 & 6;

