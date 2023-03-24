#define ll long long
    //We can not multiply each pair and check because Constraints
    //So we need to apply some greedy Technique
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        //Using Simple 2 Pointer Approach but this might give tle when no pair is successful and size of both is 1e5
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(1LL*spells[i]*potions[j]>=success)
                {
                    ans[i] = m-j;
                    break;
                }
            }
        }
        return ans;
    }


//To optimise the Linear search in Sorted Array we use binary Search approach as potions array is sorted
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end()); //Now Potions array is sorted
        int n = spells.size();
        int m = potions.size();
        
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            int f=0, l = m-1;
            int temp = -1; //we need to maintain a temp to check if our case is even valid for 1 or not, else instead of 0 it gives 1
            while(f<=l)
            {
                int mid = f + (l-f)/2;
                if(1LL*spells[i]*potions[mid]>=success) //minimise
                {
                    l = mid-1;
                    temp = mid;
                }
                else
                {
                    f = mid+1;
                }
            }
            if(temp == -1) //no pair found
                ans[i] = 0;
            else
                ans[i] = m-temp;
        }
        return ans;
    }