#include <bits/stdc++.h>
class minHeap
{
    vector<int> arr;

public:
    // Constructor for the class.
    minHeap()
    {
    }
    int parent(int node)
    {
        return (node - 1) / 2;
    }
    int left(int node)
    {
        return 2 * node + 1;
    }
    int right(int node)
    {
        return 2 * node + 2;
    }
    // Implement the function to heapify the heap.
    void heapify(int node)
    {
        int l = left(node);
        int r = right(node);
        int size = arr.size();
        int smallest = node;
        if (l < size && arr[l] < arr[node])
        {
            smallest = l;
        }
        if (r < size && arr[r] < arr[smallest])
        {
            smallest = r;
        }
        if (smallest != node)
        {
            swap(arr[smallest], arr[node]);
            heapify(smallest);
        }
    }
    void heapify_up(int i)
    {
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            heapify_up(parent(i));
        }
    }
    // Implement the function to insert 'val' in the heap.
    void insert(int val)
    {
        arr.push_back(val);
        // get element index and call heapify-up procedure
        int index = arr.size() - 1;
        heapify_up(index);
    }

    // Implement the function to remove minimum element.
    void removeMin()
    {
        if (arr.size() == 0)
            return;
        else if (arr.size() == 1)
        {
            arr.pop_back();
        }
        else
        {
            swap(arr[0], arr[arr.size() - 1]);
            arr.pop_back();
            heapify(0);
        }
    }

    // Implement the function to return minimum element.
    int minElement()
    {
        if (arr.size() == 0)
            return -1;
        else
            return arr[0];
    }
};