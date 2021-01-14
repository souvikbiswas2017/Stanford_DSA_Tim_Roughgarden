#include "minheap.h"

minheap::minheap() : heap{}
{
}

minheap::~minheap()
{
}

void minheap::insert(int number)
{
    mHeap.push_back(number);
    
    int index = mHeap.size()-1;
    while(parentNode(index)>= 0 && mHeap.at(parentNode(index)) > mHeap.at(index))
    {
        swap(index, parentNode(index));
        index = parentNode(index);
    }
}


void minheap::deleteTop()
{
    size_t node = 0;
    swap(node, mHeap.size()-1);
    mHeap.pop_back();
    
    int swapChildNode = minChildNode(node);
    while(swapChildNode >= 0 && mHeap.at(node) > mHeap.at(swapChildNode))
    {
         swap(node, swapChildNode);
         node = swapChildNode;
         swapChildNode = minChildNode(node);
    }
}

int minheap::minChildNode(int node)
{
    int leftChild = leftChildNode(node) <= mHeap.size()-1 ? leftChildNode(node) : -1;
    int rightChild = rightChildNode(node) <= mHeap.size()-1 ? rightChildNode(node) : -1;
    
    if (leftChild == -1 && rightChild == -1)
        return -1;
    if (leftChild == -1)
        return rightChild;
    if (rightChild == -1)
        return leftChild;
    return mHeap.at(leftChild) <= mHeap.at(rightChild) ? leftChild : rightChild;
}