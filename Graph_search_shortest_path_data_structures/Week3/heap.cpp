#include "heap.h"

heap::heap()
{
}

heap::~heap()
{
}

int heap::parentNode(int node)
{
    return floor((node+1)/2)-1;
}

int heap::leftChildNode(int node)
{
    return 2*node+1;
}

int heap::rightChildNode(int node)
{
    return 2*node+2;
}

void heap::swap(int i, int j)
{
    int temp = mHeap.at(i);
    mHeap.at(i) = mHeap.at(j);
    mHeap.at(j) = temp;
}

int heap::heapsize()
{
    return mHeap.size();
}

void heap::printheap()
{
    for (auto i : mHeap)
    {
        cout << i << " ";
    }
    cout << endl;
}