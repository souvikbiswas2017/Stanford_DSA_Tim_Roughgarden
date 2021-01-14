#include "edge.h"

edge::edge(int v1, int v2, int length) : mV1{v1}, mV2{v2}, mLength{length}
{
}

edge::~edge()
{
}

bool edge::operator==(const edge &rhs)
{
    return (mV1 == rhs.V1() && mV2 == rhs.V2() && mLength == rhs.Length());
}

bool edge::operator<(const edge &rhs)
{
    return (mLength < rhs.Length());
}
