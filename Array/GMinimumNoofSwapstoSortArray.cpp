//As Elements are Distinct// We can use Approach 1
//T.C. O(nlogn) S.C. O(2n)
int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> arr;
	    for(int i=0;i<n;i++)
	    {
	        arr.push_back({nums[i],i});
	    }
	    sort(arr.begin(),arr.end());
	    int count = 0;
	    for(int i=0;i<n;)
	    {
	        if(arr[i].second==i)
	        {
	            i++;
	            continue;
	        }
	        else
	        {
	            swap(arr[i],arr[arr[i].second]);
                count++;
	        }
	    }
	    return count;
	}


//Approach 2 Works for duplicates too
//T.C. O(nlogn) S.C. O(3n)

int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    vector<pair<int,int>> arr;
	    for(int i=0;i<n;i++)
	    {
	        arr.push_back({nums[i],i});
	    }
	    sort(arr.begin(),arr.end());
	    vector<bool> vis(n,false);
	    int count = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i]==true || arr[i].second == i)
	        {
	            continue;
	        }
	        int cycleLength = 0;
	        int j =i;
	        while(vis[j]==false)
	        {
	            vis[j]=true;
	            j = arr[j].second;
	            cycleLength++;
	        }
	        count+=(cycleLength-1);
	    }
	    return count;
	}