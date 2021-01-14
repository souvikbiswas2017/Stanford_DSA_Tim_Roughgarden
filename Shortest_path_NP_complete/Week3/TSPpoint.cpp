#include "TSPpoint.h"
#include <cmath>

TSPpoint::TSPpoint(int number, double x, double y): mNumber{number}, mX{x}, mY{y}, alreadyANeighbor{false}
{
}

TSPpoint::~TSPpoint()
{
}

double TSPpoint::SqDistance(TSPpoint* p)
{
    double retval{0.0};
    retval += pow(this->X()-p->X(),2);
    retval += pow(this->Y()-p->Y(),2);
    return retval;
}

void TSPpoint::setNearestPoint(TSPpoint* nearestPoint)
{
    mNearestPoint = nearestPoint;
}

double TSPpoint::getTSPedgecost()
{
    if(mNearestPoint == nullptr)
        return 0.0;
    return sqrt(this->SqDistance(mNearestPoint));
}

