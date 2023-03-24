//O(nlogn)  Approach
#define ll long long
    bool isValid(ll mid, ll neededApples)
    {
        //count no of apples in mid size square
        ll apples = 0;
        for(ll i=1;i<=mid;i++)
        {
            apples += i*4;
            apples += i*2*4;
            
            ll mn = i+1;
            ll mx = i*2 - 1;
            apples +=  (mx-mn+1)*(mn+mx)*4; 
        }
        return apples>=neededApples;
    }
    long long minimumPerimeter(long long neededApples) {
        ll l = 1;
        ll r = 1000000; //For 1e7 this nlogn gives tle
        while(l<r)
        {
            ll mid = l + (r-l)/2; //side of square
            if(isValid(mid,neededApples))
            {
                //minimize
                r = mid; //is a potential ans
            }
            else
            {
                l = mid+1;
            }
        }
        return r*8;
    }


// Better Approach is to reduce the o(n) where we are using for loop to calculate apples 
//direct formula i derived

//O(logn) Approach
//2*(mid)*(mid+1)*(2*mid+1) 


// that is summation of Summation 12*i^2 where i varies from 1 to mid