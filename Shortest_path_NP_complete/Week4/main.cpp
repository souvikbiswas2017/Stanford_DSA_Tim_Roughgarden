#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include "vertex.h"

using namespace std;
void initVertices(int nVertices, map<int, vertex*> &vertices);
void deleteVertices(map<int, vertex*> &vertices);
int readGraph(string filename, int &nVertices, map<int, vertex*> &vertices);
void reverseTraversal(map<int, vertex*> &vertices, stack<vertex*> &stack_vertices);
void forwardTraversal(stack<vertex*> &stack_vertices);
bool is2SAT(int nVertices, map<int, vertex*> &vertices);


int main()
{
    string filename{"../2sat1.txt"};
    int nVertices{};
    map<int, vertex*> vertices;
    map<int, vertex*>::iterator it;
    stack<vertex*> stack_vertices;
    readGraph(filename, nVertices, vertices);
    cout << "Number of vertices: " << nVertices << endl;
    
    reverseTraversal(vertices, stack_vertices);

    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        vertex* v = it->second;
        v->setInspected(false);
    }
    
    forwardTraversal(stack_vertices);
    
    if(is2SAT(nVertices, vertices))
        cout << "Satisfiable" << endl;
    else
        cout << "Unsatisfiable" << endl;
    deleteVertices(vertices);

}

bool is2SAT(int nVertices, map<int, vertex*> &vertices)
{
    for(int i{1}; i <= nVertices; i++)
    {
        if (vertices[i]->getGroup() == vertices[-i]->getGroup())
        {
            cout << "variable number : " << i << " is unsatisfiable" << endl;
            return false;
        }
    }
    return true;
}

void initVertices(int nVertices, map<int, vertex*> &vertices)
{
    for(int i{1}; i <= nVertices; i++)
    {
        vertices[i] = new vertex(i);
        vertices[-i] = new vertex(-i);
    }        
}
void deleteVertices(map<int, vertex*> &vertices)
{
    map<int, vertex*>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        vertex* v = it->second;
        delete v;
    }
    vertices.clear();
}
int readGraph(string filename, int &nVertices, map<int, vertex*> &vertices)
{
    
    ifstream infile;        
    string line{""};
    int firstvertex{};
    int secondvertex{};
    
    infile.open(filename);
    if(!infile)
    {
        cerr << "Problem Opening File";
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);

    infile >> nVertices;
    initVertices(nVertices, vertices);
      
    while(infile >> firstvertex >> secondvertex)
    {
        int v1 = -firstvertex;
        int v2 = secondvertex;
        vertices[v1]->addForwardConnection(vertices[v2]);
        vertices[v2]->addBackwardConnection(vertices[v1]);
        v1 = -secondvertex;
        v2 = firstvertex;
        vertices[v1]->addForwardConnection(vertices[v2]);
        vertices[v2]->addBackwardConnection(vertices[v1]);
    }
    infile.close();
    return 0;
}

void reverseTraversal(map<int, vertex*> &vertices, stack<vertex*> &stack_vertices)
{
    map<int, vertex*>::iterator it;
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        vertex* v = it->second;
        if (!v->isInspected())
        {
            stack<vertex*> dfsStack;
            dfsStack.push(v);
            while(!dfsStack.empty())
            {
                vertex* top = dfsStack.top();
                dfsStack.pop();
                top->setInspected(true);
                if(!top->isAllBackwardNeighborInspected())
                {
                    dfsStack.push(top);
                    for (vertex* conn : top->getBackwardConnections())
                        if(!conn->isInspected())
                            dfsStack.push(conn);
                }
                else
                    stack_vertices.push(top);
            }
        }
    }
}

void forwardTraversal(stack<vertex*> &stack_vertices)
{
    int groupNumber{0};
    while (!stack_vertices.empty())
    {
        vertex* v = stack_vertices.top();
        stack_vertices.pop();
        if (!v->isInspected())
        {
            stack<vertex*> dfsStack;
            dfsStack.push(v);
            groupNumber++;
            while(!dfsStack.empty())
            {
                vertex* top = dfsStack.top();
                dfsStack.pop();
                top->setInspected(true);
                top->setGroup(groupNumber);
                
                for (vertex* conn : top->getForwardConnections())
                    if (!conn->isInspected())
                        dfsStack.push(conn);
            }
        }
    }
}