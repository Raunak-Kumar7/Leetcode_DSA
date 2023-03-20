int minFlips(int a, int b, int c) {
        //Similar to 2220
        //Here we will calc a|b , now do a|b ^ c
        //now wherever bit is 0 --> means same so dont change
        //now wherever bit is 1 --> a|b and c have different bits
        //2 cases 1)c has 1 and a,b have 0, 0 --> so flip any 1 a or b, moves = 1
        //2) c has 0 and a or b or both have 1 --> so flip any 1 to 0 moves 1 or 2
        //So both case will have atleast 1 move == number of 1s in a|b ^c
        //for second case we also need to check whether a or b have single 1 or both have 1 --> and operation --> if both have 1 we add 1 to answer
        
                //both ccase give 1           //to handle 2nd case of double 11 at locations where (a|b ^ c) is 1
        return __builtin_popcount((a|b)^c) +  __builtin_popcount((a&b&((a|b)^c)));
        
    }