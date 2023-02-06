    //Brute Force: Approach 1
    //Shift array by 1 element k times T.C. O(n*k) S.C O(1)
    //Approach 2: Make Another array T.C O(n) S.C. O(n)
    void rotate(vector<int>& nums, int k) {
        //Optimal Approach using reverse
        //Reverse entire array --> reverse first k elements + reverse last n-k elements
        //By doing reverse we make starting elements reach end of array
        int n = nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%n); //Both inclusive when giving +k
        reverse(nums.begin()+k%n,nums.end());
        //Do k%n if k>n
    }