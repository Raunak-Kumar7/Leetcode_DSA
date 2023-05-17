#include <bits/stdc++.h>
using namespace std;

class maxHeap{
    public:
        vector<int> arr; //or we could use a dynamically allocated array int* arr;
        int maxSize;
        int heapSize; //Current number of elements in Heap
        maxHeap(int maxSize) //Constructor (no return type)
        {
            maxSize = maxSize;
            heapSize = 0;
            arr.resize(maxSize);
        }
        int parent(int i)
        {
            return i/2;
        }
        int leftChild(int i)
        {
            return 2*i + 1; //0 based indexing
        }
        int rightChild(int i)
        {
            return 2*i + 2;
        }
        int getMax()    //--> top function
        {
            return arr[0];
        }
        int size()
        {
            return heapSize;
        }
        void insert(int key)
        {
            if(heapSize == maxSize)
            {
                cout << "Heap is Full\n";
                return;
            }
            //insert at last then keep going up and putting in correct place
            int i = heapSize;
            arr[i] = key;
            heapSize++;
            int p = parent(i);
            while(i!=0 && arr[i] > arr[p])
            {
                swap(arr[i],arr[p]);
                i = p;
            }
        }
        void maxHeapify(int i)  //recursive
        {
            int l = leftChild(i);
            int r = rightChild(i);
            int largest = i;
            if(l < heapSize && arr[i]<arr[l])
                largest = l;
            if(r < heapSize && arr[largest]<arr[r])
                largest = r;

            if(largest!=i) //parent needs to be put in place
            {
                swap(arr[i],arr[largest]);
                maxHeapify(largest);
            
            }
        }
               
        int removeMax()   //--> Pop function with return value
        {
            if(heapSize <= 0) //empty
                return INT_MIN;
            if(heapSize == 1)  //single element
            {
                heapSize--;
                return arr[0];
            }

            //Put the last element in the array in place of MaxElement i.e. root
            //then Apply heapify, keep swapping with greater valued child until greater than both the childrem
            int ans = arr[0];
            arr[0] = arr[heapSize-1];
            heapSize--;
            maxHeapify(0);  //root node is 0
            return ans;
        }
        void increaseKey(int i, int newValue) //keep going up and check if parent is greater than it or i!=0 , if not swap
        {
            int p = parent(i);
            arr[i] = newValue;
            while(i!=0 && arr[p] < arr[i])
            {
                swap(arr[p],arr[i]);
                i = p; //index changed to upper node for further comparisons
            }
        }

        void deleteKey(int i)   
        {
            increaseKey(i,INT_MAX);   //increase node value to infinity then it comes to root -> then remove root
            removeMax();
        }

};


int main()
{
    maxHeap pq(15);
    for(int i=0;i<7;i++)
    {
        int t;
        cin>>t;
        pq.insert(t);
    }
    cout<<"Current Size of Max heap is "<<pq.size()<<endl;
    cout<<"Maximum element is (top) "<<pq.getMax()<<endl;
    pq.deleteKey(2);

    cout<<"Current Size of Max heap is "<<pq.size()<<endl;

    pq.insert(20);
    cout<<"Maximum element is (top) "<<pq.getMax()<<endl;

}