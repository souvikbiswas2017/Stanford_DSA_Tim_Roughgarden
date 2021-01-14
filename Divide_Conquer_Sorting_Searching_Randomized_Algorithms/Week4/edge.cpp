#include "edge.h"

edge::edge(int first, int second)
{
    myFirstVertex = first;
    mySecondVertex = second;
    sortVertices();
}

edge::~edge()
{
}

void edge::setVertices(int first, int second)
{
    myFirstVertex = first;
    mySecondVertex = second;
    sortVertices();
}

void edge::replaceVertex(int oldVertex, int newVertex)
{
    if (myFirstVertex == oldVertex)
        myFirstVertex = newVertex;
    if (mySecondVertex == oldVertex)
        mySecondVertex = newVertex;
    sortVertices();
}

bool edge::contains(int vertex)
{
    if (vertex == myFirstVertex || vertex == mySecondVertex)
        return true;
    return false;
}

void edge::sortVertices()
{
    if (myFirstVertex > mySecondVertex)
    {
        int temp = myFirstVertex;
        myFirstVertex = mySecondVertex;
        mySecondVertex = temp;
    }
}

bool edge::operator ==(const edge &rhs) const
{
    if (myFirstVertex == rhs.FirstVertex() && mySecondVertex == rhs.SecondVertex())
        return true;
    return false;
}

bool edge::operator <(const edge &rhs) const
{
    if (myFirstVertex < rhs.FirstVertex())
        return true;
    if (myFirstVertex == rhs.FirstVertex() && mySecondVertex < rhs.SecondVertex())
        return true;
    return false;
}

