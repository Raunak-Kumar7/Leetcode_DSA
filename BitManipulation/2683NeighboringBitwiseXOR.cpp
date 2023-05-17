 /////DO PROVE

//  orginal: A[0], A[1], .... A[n-1]
// derived: A[0]^A[1], A[1]^A[2] .... A[n-1]^A[0]

// xor(derived) = (A[0]^A[1])^(A[1]^A[2])^ .... ^(A[n-1]^A[0]) = 0

// The necessary and suffisant condition for derived to have an original is
// xor(derived) == 0
 
 
    bool doesValidArrayExist(vector<int>& derived) {
        int x = derived[0];
        int n = derived.size();
        for(int i=1;i<n;i++)
        {
            x^=derived[i];
        }
        return !x;
    }



    //Additional observation
    // Whend original and derived is binary sequence,
// this equals to sum(derived) % 2 == 0

bool doesValidArrayExist(vector<int>& A) {
        return accumulate(A.begin(), A.end(), 0) % 2 == 0;
    }