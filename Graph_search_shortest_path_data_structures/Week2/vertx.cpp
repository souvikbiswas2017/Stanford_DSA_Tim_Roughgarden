#include "vertx.h"

vertx::vertx(int vertxNumber) : mVertxNumber{vertxNumber}, mMinDistance{1000000}, mProcessed{false}
{
}

vertx::~vertx()
{
}

void vertx::addWeight(vertx* v, int weight)
{
    weights[v] = weight;
}

bool vertx::operator==(const vertx &rhs)
{
    if (mVertxNumber == rhs.getVertxNumber())
        return true;
    return false;
}
bool vertx::operator<(const vertx &rhs)
{
    if (mVertxNumber < rhs.getVertxNumber())
        return true;
    return false;
}

void vertx::Process(int minDistance)
{
    if (minDistance < mMinDistance)
    {
        mMinDistance = minDistance;
        mProcessed = true;
    }

}

map<vertx*, int> vertx::getWeights()
{
    return weights;
}