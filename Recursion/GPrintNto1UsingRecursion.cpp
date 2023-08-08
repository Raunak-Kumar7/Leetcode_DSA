// Method 1: without index
void printNos(int N)
{
    if (N == 0)
        return;

    cout << N << " ";
    printNos(N - 1);
}

// Method 2 : using index
void f(int i, int n)
{
    if (i > n)
        return;

    f(i + 1, n);
    cout << i << " "; // printing while returning i.e. moving up the recursion tree
}
void printNos(int N)
{
    f(1, N);
}