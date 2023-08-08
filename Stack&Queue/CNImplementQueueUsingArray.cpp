class Queue
{
public:
    int *arr;
    int size;
    int f;
    int back;
    Queue()
    {
        // Implement the Constructor
        size = 100001;
        arr = new int[size];
        f = 0;
        back = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return f == back;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        arr[back] = data;
        back++;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (f != back)
            return arr[f++];
        else
            return -1;
    }

    int front()
    {
        // Implement the front() function
        if (f != back)
            return arr[f];
        else
            return -1;
    }
};

// circular array approach %n,

class Queue
{

    int front, rear;
    vector<int> arr;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        arr.resize(100); // using circular array approach %n, can declare a large size though
    }

    // Enqueue (add) element 'e' at the end of the queue.
    void enqueue(int e)
    {
        arr[rear] = e;
        rear = (rear + 1) % 100;
    }

    // Dequeue (retrieve) the element from the front of the queue.
    int dequeue()
    {
        if (front == rear)
            return -1;
        int ans = arr[front];
        front = (front + 1) % 100;
        return ans;
    }
};