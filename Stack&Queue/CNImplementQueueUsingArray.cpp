class Queue {
public:
    int *arr;
    int size;
    int f;
    int back;
    Queue() {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        f =0;
        back =0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return f==back ;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[back] = data;
        back++;

    }

    int dequeue() {
        // Implement the dequeue() function
        if(f!=back)
            return arr[f++];
        else 
            return -1;
    }

    int front() {
        // Implement the front() function
        if(f!=back)
            return arr[f];
        else
            return -1;
    }
};