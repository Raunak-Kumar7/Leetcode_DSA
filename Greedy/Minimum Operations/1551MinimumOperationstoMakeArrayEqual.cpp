//make pairs of left and right most and so on
    //If n == odd , we make every element equal to the mid element
    //if n == even , we make every element equal to mid of the middle 2
    
    //Observation n is the number to which we have to change every number
    //We can obviously implement now in O(n) approach by sum+=abs(n-arr[i])
    
    //To do it directly O(1) Approach 
    // n is odd --> ans is sum of even numbers less than n
    // n is even --> ans is sum of odd numbers less than n
    
    int minOperations(int n) {
        if(n%2==1)
        {
            int half = n/2;
            return half*(half+1); //2*(n)*(n+1)/2
        }
        else
        {
            int half = n/2;
            return half*(half+1) - half; 
        }
    }


