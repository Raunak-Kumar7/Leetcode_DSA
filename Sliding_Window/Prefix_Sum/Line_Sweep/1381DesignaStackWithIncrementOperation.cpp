// Also implemented brute force in lc

// https://www.youtube.com/watch?v=-CXN5Nh9jOA
    //LAZY INCREMENT (similar to Line Sweep)
    // --------------Important Concept----------------//

    vector<int> st;
    vector<int> inc;
    int idx; //top index
    int mx;
    CustomStack(int maxSize) { //implemented stack using array
        st.resize(maxSize);
        inc.resize(maxSize); //global initialised to 0
        idx = -1;
        mx = maxSize;
    }
    
    void push(int x) {
        if(idx==mx-1) return;
        st[++idx] = x;
    }
    
    int pop() {
        if(idx == -1) return -1;
        int ans = st[idx] + inc[idx];
        if(idx-1>=0) inc[idx-1]+=inc[idx];
        inc[idx] = 0;
        st[idx] = 0;
        idx--;
        return ans;
    }
    
    void increment(int k, int val) {
        if(idx > -1 )
            inc[min(k-1,idx)]+=val; //k elements --> k-1
    }





// Brute Force
    vector<int> st;
    int idx;
    int mx;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        idx = -1;
        mx = maxSize;
    }
    
    void push(int x) {
        if(idx==mx-1) return;
        st[++idx] = x;
    }
    
    int pop() {
        if(idx!=-1)
            return st[idx--];
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<=min(k-1,idx);i++)
            st[i]+=val;
    }