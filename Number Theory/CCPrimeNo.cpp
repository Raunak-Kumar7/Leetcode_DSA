//Brute Force Approach O(n)
bool isPrime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

//Optimised Approach O(sqrt(n))
bool isPrime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++) //check equal to for perfect squares
    {
        if(n%i==0)
            return false;
    }
    return true;
}