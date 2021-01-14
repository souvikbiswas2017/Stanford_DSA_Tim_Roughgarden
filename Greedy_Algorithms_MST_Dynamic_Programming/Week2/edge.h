#pragma once

class edge
{
private:
    int mV1;
    int mV2;
    int mLength;
public:
    edge(int v1, int v2, int length);
    ~edge();
    bool operator==(const edge &rhs);
    bool operator<(const edge &rhs);
    inline int V1() const { return mV1; };
    inline int V2() const { return mV2; };
    inline int Length() const { return mLength; };
};

