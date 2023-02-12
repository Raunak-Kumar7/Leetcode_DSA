 //this question means find a sbstring of max length with at most k 0s 
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int i=0;
        int j=0;
        int count=0; //number of zeros
        int mx = 0;
        while(j<n)
        {
            if(arr[j]==0) //calculations
            {
                count++;
            }
            if(count<k) //can still increase size of subarray
            {
                mx = max(mx,j-i+1);  //if it never reaches k
                j++;
            }
            else if(count==k)  //what if count never reaches k
            {
                mx = max(mx,j-i+1);
                j++;
            }
            else if(count>k)
            {
                while(count>k)
                {
                    if(arr[i]==1)
                    {
                        i++;
                    }
                    else
                    {
                        i++;
                        count--;
                    }
                }
                j++;
            }
            
        }
        return mx;
    }