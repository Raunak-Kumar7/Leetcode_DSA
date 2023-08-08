
// M1- Create window of each size, for every window find max without sliding window tech --> O(n^2), O(1)
// M2- Using Sliding window create window of each size 1 - N --> O(n^2), O(1)
class Solution
{
    // Optimised Stack Approach
    // Step1: finding the range of each value till where it can be be the king
    // idx ( 0, 1, 2, 3, 4, 5, 6)
    // Eg. [10,20,30,50,10,70,30]
    //.   [ 7, 3, 2, 1, 7, 1, 2]. //size of window till of which it can considered Minimum //To calculate this array we use NSE technique(using stack) same as we did in LARGEST AREA IN HISTOGRAM
    // Now for eg, 10 has a value of 7, so it is also valid for all window size of less than 7 i.e.[1,7]
    // So now we make answer array and pick only maximum value for each window size i.e. at WS 1 we have 70 and 50 both so we use 70 bcz it is max at WS 1
    //. WS[ 1, 2, 3, 4, 5, 6, 7]
    // Ans [70,30,20,  ,  ,  ,10] //70>50 so pick 70 instead of 50
    // now for WS 4,5,6 we didnt find any value , but we know that 10 is valid for all WS lesser than 7 so
    // Ans [70,30,20,10,10,10,10]

public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> dist(n);
        stack<int> st;
        vector<int> nsel(n, -1);
        vector<int> nser(n, n);
        // Finding NSE left
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nsel[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty()) // to reuse the same stack empty it first
        {
            st.pop();
        }
        // Finding NSE R
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                nser[i] = st.top();
            }
            st.push(i);
        }
        // finding size of window in which element is king i.e. smallest
        for (int i = 0; i < n; i++)
        {
            dist[i] = (nser[i] - nsel[i] - 1);
        }
        // finding ans vector
        vector<int> ans(n, 0); // length of WS 1-7, 0 based indexing
        for (int i = 0; i < n; i++)
        {
            ans[dist[i] - 1] = max(ans[dist[i] - 1], arr[i]);
        }
        // Filling in missing values in ans
        for (int i = n - 2; i >= 0; i--) // last value is always filled
        {
            ans[i] = max(ans[i], ans[i + 1]);
        }
        return ans;
    }
};