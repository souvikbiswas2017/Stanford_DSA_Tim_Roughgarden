#pragma once
#include "heap.h"
class minheap: public heap
{
private:
    int minChildNode(int node);
public:
    minheap();
    ~minheap();
    virtual void insert(int number) override;
    virtual void deleteTop() override; 
};

