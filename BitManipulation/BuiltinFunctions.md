
## __builtin_popcount(x)
## __builtin_parity(x)
## __builtin_clz(x)
## __builtin_ctz(x)



## Count Number of Set Bits

__builtin_popcount(x);
__builtin_popcountl(x);   //for long data type
__builtin_popcountll(x);


## Check Parity of Number

Odd Parity--> number of set bits = odd

Returns 1 if odd parity , 0 if even parity

__builtin_parity(x);
__builtin_parityl(x);
__builtin_parityll(x);


## Count Number of Leading zeros

a = 16
Binary form of 16 is 00000000 00000000 00000000 00010000
Output: 27

__builtin_clz(x);
__builtin_clzl(x);
__builtin_clzll(x);

## Count number of Trailing Zeros

a = 16
Binary form of 16 is 00000000 00000000 00000000 00010000
Output: 4

__builtin_ctz(x);
__builtin_ctzl(x);
__builtin_ctzll(x);


