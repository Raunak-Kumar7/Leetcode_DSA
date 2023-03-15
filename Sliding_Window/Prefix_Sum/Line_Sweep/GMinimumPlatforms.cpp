//Using Line Sweep Technique (Prefix Sum) //OPTIMISED
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> prefix(2400,0);
    	for(int i=0;i<n;i++)
    	{
    	    prefix[arr[i]]++;
    	    prefix[dep[i]+1]--;
    	}
    	//forming the prefix array
    	int maxi = prefix[0];
    	for(int i=1;i<2400;i++)
    	{
    	    
    	    prefix[i] = prefix[i-1] + prefix[i];
    	    maxi = max(maxi, prefix[i]);
    	}
    	return maxi;
    	
    }