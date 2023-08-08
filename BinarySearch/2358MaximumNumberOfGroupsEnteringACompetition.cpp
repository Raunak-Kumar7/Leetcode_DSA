// T.C. O(log(1000))
// Observations:
// We will always be able to divide students in increasing size and increasing sums if we have a sorted grades array
// to have max number of groups we need to divide the groups having sizes as 1,2,3,4... (General Case)
//  but for cases like [8,8,8,8,8] or [1,2,3,4,5] we can only divide in 2 groups  of sizes 1 and 4(greedily)
// now to check max groups we need to find the n for which sum of natural number is less than or equal to the number of elements in the array (natural number --> number of people in 1 group 1,2,3,4,....)
int maximumGroups(vector<int> &grades)
{
    int n = grades.size();
    int f = 1;
    int l = 1000; /// n*(n+1)/2 --> 1000 will cover 1e5
    int ans = 0;
    while (f <= l)
    {
        int mid = (f + l) / 2;
        if ((mid * (mid + 1) / 2) <= n)
        {
            ans = mid;
            f = mid + 1;
        }
        else
        {
            l = mid - 1;
        }
    }
    return ans;
}