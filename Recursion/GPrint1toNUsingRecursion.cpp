// First go to 1 from N then print ---> First call then Print
void printTillN(int N)
{
    if (N == 0)
        return;

    printTillN(N - 1);
    cout << N << " ";
}

// Method - 2  Using Index
void f(int i, int n)
{
    if (i > n)
        return;
    cout << i << " ";
    f(i + 1, n);
}
void printTillN(int N)
{
    f(1, N);
}