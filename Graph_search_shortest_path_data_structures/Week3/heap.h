#pragma once
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
class heap
{
private:
protected:
    vector<int> mHeap;
    int parentNode(int node);
    int leftChildNode(int node);
    int rightChildNode(int node);
    void swap(int i, int j);
public:
    heap();
    ~heap();
    virtual void insert(int number) = 0;
    virtual void deleteTop()=0;
    inline int getTop() {return mHeap.at(0); };
    virtual void printheap();
    virtual int heapsize();
};

