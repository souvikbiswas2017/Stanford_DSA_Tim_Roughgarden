#pragma once

class edge
{
private:
    int myFirstVertex;
    int mySecondVertex;
    void sortVertices();
public:
    edge(int first, int second);
    ~edge();
    inline int FirstVertex() const {return myFirstVertex;};
    inline int SecondVertex() const {return mySecondVertex;};
    void setVertices(int first, int second);
    void replaceVertex(int original, int replace);
    bool contains(int vertex);
    bool operator==(const edge &rhs) const; // equals
    bool operator<(const edge &rhs) const; //less than
    bool operator>(const edge &rhs) const; //greater than
};

