#include "maxheap.h"

maxheap::maxheap() : heap{}
{
}

maxheap::~maxheap()
{
}

void maxheap::insert(int number)
{
    mHeap.push_back(number);
    
    int index = mHeap.size()-1;
    while(parentNode(index)>= 0 && mHeap.at(parentNode(index)) < mHeap.at(index))
    {
        swap(index, parentNode(index));
        index = parentNode(index);
    }
}

void maxheap::deleteTop()
{
    size_t node = 0;
    swap(node, mHeap.size()-1);
    mHeap.pop_back();
    
    int swapChildNode = maxChildNode(node);
    while(swapChildNode >= 0 && mHeap.at(node) < mHeap.at(swapChildNode))
    {
         swap(node, swapChildNode);
         node = swapChildNode;
         swapChildNode = maxChildNode(node);
    }
}

int maxheap::maxChildNode(int node)
{
    int leftChild = leftChildNode(node) <= mHeap.size()-1 ? leftChildNode(node) : -1;
    int rightChild = rightChildNode(node) <= mHeap.size()-1 ? rightChildNode(node) : -1;
    
    if (leftChild == -1 && rightChild == -1)
        return -1;
    if (leftChild == -1)
        return rightChild;
    if (rightChild == -1)
        return leftChild;
    return mHeap.at(leftChild) >= mHeap.at(rightChild) ? leftChild : rightChild;
}