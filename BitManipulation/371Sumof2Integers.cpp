// https://leetcode.com/problems/sum-of-two-integers/discuss/84278/A-summary%3A-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently

// https://youtu.be/gVUrDV4tZfY

    //Xor gives sum 
    //and gives carry
    int getSum(int a, int b) {
        while(b!=0)
        {
            int temp =  (unsigned int)(a&b)<<1;  //without unsigned int there is error
            a = a^b;
            b = temp; //left shifted because carry is added to the bit on left
        }
        return a;
    }




// does overflow int
int getSum(int a, int b) {
        return log(exp(a)*exp(b)); 
    }