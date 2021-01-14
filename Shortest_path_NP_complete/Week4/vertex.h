#pragma once
#include <vector>
#include <string>
#include <stack>
using namespace std;
class vertex
{
private:
    int mVertexNumber;
    int mGroup;
    vector<vertex*> mForwardConnections;
    vector<vertex*> mBackwardConnections;
    bool mInspected;
public:
    vertex(int vertexNumber);
    ~vertex();
    void addForwardConnection(vertex* v);
    void addBackwardConnection(vertex* v);
    inline int getVertexNumber() {return mVertexNumber; };
    inline vector<vertex*> getForwardConnections() { return mForwardConnections; } ;
    inline vector<vertex*> getBackwardConnections() { return mBackwardConnections; };
    string displayForwardConnections();
    string displayBackwardConnections();
    inline bool isInspected() {return mInspected; };
    inline void setInspected(bool inspected) {mInspected = inspected; };
    inline void setGroup(int groupNumber) {mGroup = groupNumber; };
    inline int getGroup() {return mGroup; };
    bool isAllBackwardNeighborInspected();
};

