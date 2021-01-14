#pragma once
#include <vector>
using namespace std;
class TSPpoint
{
private:
    int mNumber;
    double mX, mY;
    TSPpoint* mNearestPoint = nullptr;
public:
    TSPpoint(int number, double x, double y);
    ~TSPpoint();
    inline double X() { return mX; };
    inline double Y() { return mY; };
    double SqDistance(TSPpoint* p);
    bool alreadyANeighbor;
    void setNearestPoint(TSPpoint* nearestPoint);
    inline TSPpoint* getNearestPoint() { return mNearestPoint; };
    inline int getNumber() { return mNumber; };
    double getTSPedgecost();
};

