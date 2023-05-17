//Sort the jobs by proft, when pick a job pick the last availabe deadline time for it
    //Here job duration is 1 for all jobs
    static bool comp(Job a,Job b)
    {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        //sort by profit
        sort(arr,arr+n,comp);
        vector<int> time(n+1,0); //max deadline = n
        time[0] = 1;
        vector<int> ans(2,0); //{count,profit}
        for(int i=0;i<n;i++)
        {
            int ded = arr[i].dead;
            while(time[ded]!=0 && ded>=0)
                ded--;
            if(ded>0)
            {
                time[ded] = arr[i].id;
                ans[0]++;
                ans[1]+=arr[i].profit;
            }
        }
        return ans;
    } 