    //GOOD QUESTION
    
    //First Thought: Make the difference array reward1 - reward2
    //Sort based on the diff array
    //Start picking max of the 2 satisfying the conditions of k and n-k
    //Greedy Approach
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int,int>> diff; //Stores diff and index
        for(int i=0;i<n;i++) 
        {
            diff.push_back({abs(reward1[i]-reward2[i]),i});
        }
        sort(diff.begin(),diff.end(), greater<pair<int,int>>()); //sort in decreasing order
        
        int y = n-k; //number of elements from reward2 
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int idx = diff[i].second;
            //pick the greater element till you can
            if(reward1[idx]>reward2[idx] && k>0)
            {
                ans+=reward1[idx];
                k--;
            }
            else if(reward1[idx]<reward2[idx] && y>0)
            {
                ans+=reward2[idx];
                y--;
            }
            else
            {
                ans+=min(reward1[idx],reward2[idx]);
            }
        }
        return ans;
    }



    //can be thought as of
    //All the cheese is eaten by 2nd mice
    //now we want 1st mice to have k cheese and those k cheese should be left by 2nd mice even if we are in a loss
    //so mice1 will eat those which have the highest diff to maximize profit
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> diff;
        int n = reward1.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            diff.push_back(reward1[i]-reward2[i]); //no need to take the abs diff
            ans+=reward2[i]; //mice2 ate all
        }
        sort(diff.begin(),diff.end(),greater<int>()); //at first index we have max of diff
        //now mice 1 will have to eat k and mice 2 will have to leave those k 
        for(int i=0;i<k;i++)
            ans+=diff[i]; //(this means we are removing reward2 from ans and adding reward1 where the diff is highest i.e. reward1 is >> reward2)
        return ans;
        
    }

/////2nd soln is better and more intuitive than 3rd


    //can be thought as of
    //All the cheese is eaten by 2nd mice
    //now we want 1st mice to have k cheese and those k cheese should be left by 2nd mice even if we are in a loss
    //so mice1 will eat those which have the highest diff to maximize profit
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> diff;
        int n = reward1.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            diff.push_back(reward2[i]-reward1[i]); //no need to take the abs diff
            ans+=reward2[i]; //mice2 ate all
        }
        sort(diff.begin(),diff.end()); //at first index we have min of diff
        //now mice 1 will have to eat k and mice 2 will have to leave those k i.e. diff of first k will be removed from ans even though it may decrease the previous val of ans
        for(int i=0;i<k;i++)
            ans-=diff[i]; //(this means we are removing reward2 from ans and adding reward1 where the diff is lowest i.e. reward1 is >> reward2)
        return ans;
        
    }