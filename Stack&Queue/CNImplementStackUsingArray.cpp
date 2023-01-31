class Stack {
    
public:
    int * arr;
    int t;
    int n;
    Stack(int capacity) {
        // Write your code here.
        arr = new int[capacity];
        t =-1;
        n = capacity;
    }

    void push(int num) {
        // Write your code here.
        if(t<n-1) //if t==n-1 Full
        {
            arr[t+1] = num;
            t++;
        }
    }

    int pop() {
        // Write your code here.
        if (t >= 0) {
          return arr[t--];
        }
        else
            return -1;
    }
    
    int top() {
        // Write your code here.
        if (t >= 0) {
          return arr[t];
        }
    }
    
    int isEmpty() {
        // Write your code here.
        if(t==-1) return 1;
        else return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(t==n-1) return 1;
        else return 0;
    }
    
};