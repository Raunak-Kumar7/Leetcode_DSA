```
 //seen the power array --> to precompute power of 2 Else getting RTE
        vector<int> power(n);
        power[0] = 1;
        for(int i=1;i<n;i++)
        {
            power[i] = (2*power[i-1])%mod;
        }
```

