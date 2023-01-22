//Greater than n/2

//M1 Brute Force O(n^2)
//Check frequency of each element

//M2 O(n) , O(n)
//Use Hashmap to store frequency

//M3 Optimised O(n)
//Boyre Moore Approach

int majorityElement(int a[], int size)
    {
        int count =1;
        int ele = a[0];
        for(int i=1;i<size;i++)
        {
            if(ele==a[i])
            {
                count++;
            }
            else
            {
                count--;
                if(count==0)
                {
                    count=1;
                    ele = a[i];
                }
            }
        }
        int cnt=0; //returns candidate of majority element
        for(int i=0;i<size;i++)
            if(a[i]==ele)
                cnt++;
        if(cnt>size/2)
            return ele;
        return -1;
    }
