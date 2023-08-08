// Recursive approach
bool f(int i, int j, string S)
{
    if (i >= j)
        return true;

    return ((S[i] == S[j]) && f(i + 1, j - 1, S));
}
int isPalindrome(string S)
{
    int l = S.size();
    return f(0, l - 1, S);
}