    //return maximum of every window of size k

    //Same concept as first negative
    /////STORE USEFUL ELEMENTS IN LIST/QUEUE
    
    //Fixed Sliding Window
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        vector<int> ans;
        int n = nums.size();
        list<pair<int,int>> ls; //need pop back {value,index}
        while(j<n)
        {
            while(!ls.empty() && ls.back().first<nums[j])
            {
                ls.pop_back(); //we dont need elements if we are getting a bigger one //so remove from back
            }
            ls.push_back({nums[j],j});
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if(!ls.empty())
                    ans.push_back(ls.front().first);
                if(ls.front().second==i)
                    ls.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }