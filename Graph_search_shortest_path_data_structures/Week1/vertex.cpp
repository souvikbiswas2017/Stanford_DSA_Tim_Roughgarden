#include "vertex.h"
using namespace std;

vertex::vertex(int vertexNumber) : mVertexNumber{vertexNumber}, mInspected{false}
{
}

vertex::~vertex()
{
}

void vertex::addForwardConnection(vertex* v)
{
    mForwardConnections.push_back(v);
}

void vertex::addBackwardConnection(vertex* v)
{
    mBackwardConnections.push_back(v);
}

string vertex::displayForwardConnections()
{
    string retval{};
    for(auto conn : mForwardConnections)
        retval += to_string(conn->getVertexNumber()) + " ";
    return retval;
}

string vertex::displayBackwardConnections()
{
    string retval{};
    for(auto conn : mBackwardConnections)
        retval += to_string(conn->getVertexNumber()) + " ";
    return retval;
}

bool vertex::isAllBackwardNeighborInspected()
{
    for (vertex* conn : mBackwardConnections)
        if(!conn->isInspected())
            return false;
    return true;
}
