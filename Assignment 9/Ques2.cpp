#include <iostream>
#include <vector>
using namespace std;

// ---------------------------------------------------
// Priority Queue implemented using Max Heap
// ---------------------------------------------------
class PriorityQueue
{
    vector<int> heap;

    void heapifyUp(int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i])
            {
                swap(heap[parent], heap[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void heapifyDown(int i)
    {
        int n = heap.size();
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != i)
            {
                swap(heap[i], heap[largest]);
                i = largest;
            }
            else
                break;
        }
    }

public:
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop()
    {
        if (heap.empty())
            return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top()
    {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    bool empty()
    {
        return heap.empty();
    }

    void display()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

// ---------------------------------------------------
// Main function
// ---------------------------------------------------
int main()
{
    PriorityQueue pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(40);

    cout << "Priority Queue (Max-Heap): ";
    pq.display();

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After removing top, Queue: ";
    pq.display();

    return 0;
}
