#pragma once
#include "heap.h"
class maxheap : public heap
{
private:
    int maxChildNode(int node);
public:
    maxheap();
    ~maxheap();
    virtual void insert(int number) override;
    virtual void deleteTop() override;
};

