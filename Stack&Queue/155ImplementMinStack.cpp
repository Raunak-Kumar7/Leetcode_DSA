//Approach 1 O(2N)
//Use array or vector to implement stack not Directly STL
class MinStack {
public:
    stack<pair<int,int>> s;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(val<min)
            min = val;
        s.push({val,min});
    }
    
    void pop() {
        s.pop();
        if(s.size()>=1)
        {
            min = s.top().second;
        }
        else
        {
            min = INT_MAX;
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

//Approach 2 O(N) space i.e. using variable without using extra stack space
//Implement using Array or vector not using STL
class MinStack {
public:
    stack<long long> st; //long long because we do 2*
    long long min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()) //no min till now
        {
            min = val;
            st.push(val);
        }
        else
        {
            if(val>=min)
            {
                st.push(val);
            }
            else
            {
                st.push(1LL*2*val-min);
                min = val;
            }
        }
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top()<min)
        {
            min = 1LL*2*min - st.top();
        }
        st.pop();
        if(st.empty())
        {
            min = INT_MAX;
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<min)
        {
            return min; 
        }
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};