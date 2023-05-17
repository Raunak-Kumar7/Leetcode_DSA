//IMPORTANT QUESTION --> LEARN
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    //Brute Force: For each interval find number of overlapping intervals --> take maximum
    int findPlatform(int arr[], int dep[], int n)
    {
        int result = 0;
        for (int i = 0; i < n; i++) 
        {
            int plat_needed = 1;
            for (int j = 0; j < n; j++) 
            {
                if (i != j)
                    if (arr[i] >= arr[j] && dep[j] >= arr[i]) //LEARN THIS CONDITION & UNDERSTAND HOW IT WORKS
                        plat_needed++;
        }
        result = max(plat_needed, result);
    }
        return result;
    }




// 2 pointer approach (striver)
    //Sort both arrival and departure arrays
    // Scrolling through time and add 1 when train arrives and decrease 1 when train departs
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        int i=0;
        int j=0;
        int maxi = 0;
        int currplat = 0;
        while(i<n && j<n)
        {
            if(arr[i] <= dep[j])
            {
                currplat++;
                i++;
            }
            else if(arr[i] > dep[j])
            {
                currplat--;
                j++;
            }
            maxi = max(maxi,currplat);
        }
		// in case arrival array finishes before departure array we dont need to complete the traversal of departure array bcz number of platforms will only decrease
		// and departure array can never finish before the arrival array
        return maxi;
    }



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