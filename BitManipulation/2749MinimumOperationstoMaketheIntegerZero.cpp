class Solution
{
public:
    // check if set bits in num1 - op*num2 = op
    int makeTheIntegerZero(int num1, int num2)
    {

        for (int i = 1; i < 1000000; i++) // i --> number of operations
        {
            long long temp = 1ll * num1 - 1ll * i * num2;
            if (temp <= 0)
                break;
            int x = __builtin_popcountll(temp);
            if (x <= i && temp >= i)
                return i;
        }
        return -1;
    }
};