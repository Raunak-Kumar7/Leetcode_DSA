//Similar to sqrt(x), where we were checking mid*mid, but here we will check wiht mid n times
	//Here if its not an integer we have to return -1
	int NthRoot(int n, int m)
	{
	    int l = 0; 
	    int r = m;
	    while(l<=r)
	    {
	        int mid = l + (r-l)/2;
	       // long long temp = 1;
	       // for(int i=0;i<n;i++) temp = temp*mid;
	       double temp = pow(mid,n); // Even ll gives negative values
	        if(temp==m)
	            return mid;
	        else if(temp<m)
	        {
	            l = mid+1;
	        }
	        else
	        {
	            r = mid-1;
	        }
	    }
	    return -1;
	}