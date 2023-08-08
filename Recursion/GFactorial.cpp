// Method 1: without index
long long int factorial(int N)
{
    if (N == 0)
        return 1;

    return 1ll * N * factorial(N - 1);
}

// Method 2: with index
long long f(int i, int N)
{
    if (i > N)
        return 1;

    return 1ll * i * f(i + 1, N);
}
long long int factorial(int N)
{
    if (N == 0)
        return 1;
    return f(1, N);
}