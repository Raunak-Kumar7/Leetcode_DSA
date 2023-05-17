    //Based on Kadane
    
    //observations: 
    //case: if the net sum of the array is +ve we also consider taking a case of all k subarrays  --> k*sum of array
    //case: take max sum of subarray in arr
    //case: max sum of subarray in arr*k + sum of remaining*k-1
    //case: we concat 2 arr and then check kadane
    # define MOD 1000000007
    # define ll long long
    ll kadane(vector<int>& arr)
    {
        int n = arr.size();
        int maxSum =0;
        int currSum =0;
        for(int i=0;i<n;i++)
        {
            currSum +=arr[i];
            if(currSum>maxSum)
                maxSum = currSum;
            if(currSum<0) //dont include curr element --> its the reason of negative currsum
                currSum = 0;
        }
        return maxSum;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll totalSum = accumulate(arr.begin(),arr.end(),0);
        ll maxSum = kadane(arr);
        ll remain = totalSum - maxSum;
        vector<int> two = arr;
        for(auto i:arr)
            two.push_back(i);
        ll twoSum = kadane(two);
        // cout<<totalSum<<" "<<maxSum<<" "<<remain<<" ";
        // cout<<endl;
        cout<<maxSum*k<<" "<<maxSum<<" "<<maxSum*k + (k-1)*remain<<endl;
        if(k>1)
        return max(max(twoSum,(totalSum*k)), max(maxSum,(maxSum*k + (k-1)*remain)))%MOD;
        else
            return maxSum%MOD;
    }