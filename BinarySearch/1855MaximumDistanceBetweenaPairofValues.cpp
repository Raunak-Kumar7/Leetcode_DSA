//Simple Binary Search on nums 2
    int bs(int f, int l, int key, vector<int>& nums2)
    {
        int ans = -1;
        while(f<=l)
        {
            int mid = (f+l)/2;
            if(nums2[mid]>=key)
            {
                ans = mid;
                f = mid+1;
            }
            else
            {
                l = mid-1;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0;i<n1;i++)
        {
            int dist = bs(i,n2-1,nums1[i],nums2);
            if(dist ==-1) continue;
            maxi = max(maxi,dist-i);
        }
        return maxi;
    }


//Approach 2: 2 pointers --> do