//only push,isempty is O(1) + using extra space
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        vector<int> temp;
        while(!q.empty())
        {
            temp.push_back(q.front());
            q.pop();
        }
        for(int i=0;i<temp.size()-1;i++)
            q.push(temp[i]);
        return temp[temp.size()-1];
    }
    
    int top() {
        vector<int> temp;
        while(!q.empty())
        {
            temp.push_back(q.front());
            q.pop();
        }
        for(int i=0;i<temp.size();i++)
            q.push(temp[i]);
        return temp[temp.size()-1];
    }
    
    bool empty() {
        return q.empty();
    }
};



//Only push is O(n)
//Better Solution
class Stack {
public:
	queue<int> que;
	// Push element x onto stack. //transfer all elements to back
	void push(int x) {
		que.push(x);
		for(int i=0;i<que.size()-1;++i){
			que.push(que.front());
			que.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		que.pop();
	}

	// Get the top element.
	int top() {
		return que.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return que.empty();
	}
};
