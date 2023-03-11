    //Binary search on Ans [1,totaltrips*min(time)]
    //Maximum answer which could in worst case , if the bus with smallest time does all the trips
    //minimum not defined so we take 1
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 1;
        long long end = 1LL*(*min_element(time.begin(),time.end()))*totalTrips; //can exceed int
        int n = time.size();
        while(start<end)
        {
            long long mid = (start+end)/2; //checking if totalTrips can be done in mid time
            long long trips = 0; 
            for(int i=0;i<n;i++)
            {
                trips+=(mid/time[i]);
            }
            if(trips>=totalTrips) //also taking equal time because eg, [3] and mid = 4 --> trip ==1 but if we decrease mid --> 3 then also trip is ==1 so time taken is minimized 
                end = mid; //mid can also be a possible answer so we dont do mid-1
            else
                start = mid+1; //not satisfied in mid so mid is not a possible ans
            
        }
        return end;
    }