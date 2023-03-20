int setBit(int n)
    {
        int i = 0;
        int k = n;
        int flag = -1; //to keep a check, if flag is not set it means all bits are already set
        while(k>0)
        {
            if((k&1)==0)
            {
                flag = 1;
                break;
            }
            k=k>>1;
            i++;
        }
        if(flag==-1)
            return n;
        //i has index of rightmost unset(0) bit 
        int mask = 1<<i;
        return (n|mask); 
        
    }

//If question said unset the rightmost set bit
//find location of rightmost set 1
//now we want this location to be 0 and rest as it is

//prepare mask by doing 1<<i
//now invert all bits by //// ~mask //// then perform & operation   //////Question would be similar to unset ith bit



//Extra approach : can solve it by converting it to string
