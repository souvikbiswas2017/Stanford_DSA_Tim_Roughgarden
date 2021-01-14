#pragma once
#include <map>
using namespace std;
class vertx
{
private:
    int mVertxNumber;
    int mMinDistance;
    bool mProcessed;
    map<vertx*, int> weights;

public:
    vertx(int vertxNumber);
    ~vertx();
    inline int getVertxNumber() const { return mVertxNumber; };
    void addWeight(vertx* v, int weight);
    void Process(int minDistance);
    inline bool getProcessed() { return mProcessed; };
    map<vertx*, int> getWeights();
    inline int getMinDistance() { return mMinDistance; };
    bool operator==(const vertx &rhs);
    bool operator<(const vertx &rhs);
};
