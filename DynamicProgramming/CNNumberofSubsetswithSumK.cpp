//Count Number of Ways
//Recursive Approach
int f(int i, vector<int> &num, int tar)
{
    if(tar==0) return 1; 
    if(i==0)
    {
        if(num[0]==tar) return 1;
        else return 0;
    }
    int nottake = f(i-1,num,tar);
    int take = 0;
    if(num[i]<=tar)
        take = f(i-1,num,tar-num[i],dp);
    return take+nottake;
}
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    return f(n-1,num,tar);
}


//Count Number of Ways
//Memoized Approach
int f(int i, vector<int> &num, int tar, vector<vector<int>>& dp)
{
    if(tar==0) return 1; 
    if(i==0)
    {
        if(num[0]==tar) return 1;
        else return 0;
    }
    if(dp[i][tar]!=-1) return dp[i][tar];
    int nottake = f(i-1,num,tar,dp);
    int take = 0;
    if(num[i]<=tar)
        take = f(i-1,num,tar-num[i],dp);
    return dp[i][tar] = take+nottake;
}
int findWays(vector<int> &num, int tar)
{
    //Changing Parameters i -->0,n-1  tar 0 ->tar
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1,-1));
    return f(n-1,num,tar,dp);
}


//----------BOTH THESE CODES WORK FOR NUM[i] >=1 ----------------
//TO HANDLE NUM[i]>=0 There are 2 methods

//Method 1: code remains same , only diff is that we count number of 0s separately and then 
// multiply pow(2,no. of zeros) X ans  //Becuase as 0s dont alter our sum so each 0 has 2 options either
// to be in the subset or not

//Method 2: To handle this by changing code 
// We remove the B.C. if(target==0) return ; becuase still there will be more cases to consider of 0s
// We update the B.C. if(ind==0) if arr[0] ==0 we have 2 choices return 2; if(arr[0]==sum) then we have only choice i.e. to take the arr[0] return 1; or even if sum==0 and arr[0]!=0 we still have only 1 way i.e. not take
// for all other cases return 0. i.e we are at index 0 and arr[0]!=sum

//Updated code for num[i]>=0
//Count Number of Ways
//Memoized Approach
int f(int i, vector<int> &num, int tar, vector<vector<int>>& dp)
{
    if(i==0)
    {
        if(num[0]==0 && tar==0) return 2;
        if(tar==0 || tar==num[0]) return 1; //there is only 1 way by not taking if sum==0 and only 1 way by taking if sum ==num[0]
        return 0;
    }
    if(dp[i][tar]!=-1) return dp[i][tar];
    int nottake = f(i-1,num,tar,dp);
    int take = 0;
    if(num[i]<=tar)
        take = f(i-1,num,tar-num[i],dp);
    return dp[i][tar] = take+nottake;
}
int findWays(vector<int> &num, int tar)
{
    //Changing Parameters i -->0,n-1  tar 0 ->tar
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (tar+1,-1));
    return f(n-1,num,tar,dp);
}


