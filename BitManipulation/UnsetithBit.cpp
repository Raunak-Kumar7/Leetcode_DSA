unsetBit(int n, int i)
{
    int mask = ~(1<<i);
    return (n&mask);
}