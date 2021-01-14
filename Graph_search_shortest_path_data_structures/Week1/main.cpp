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
int readGraph(string filename, map<int, vertex*> &vertices);
void reverseTraversal(map<int, vertex*> &vertices, stack<vertex*> &stack_vertices);
void forwardTraversal(stack<vertex*> &stack_vertices);


int main()
{
    string filename{"../largeSCC.txt"};
    map<int, vertex*> vertices;
    map<int, int> groups;
    map<int, vertex*>::iterator it;
    stack<vertex*> stack_vertices;
    initVertices(320000,vertices);
    readGraph(filename,vertices);
    cout << "Number of vertices: " << vertices.size() << endl;
    
    reverseTraversal(vertices, stack_vertices);

    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        vertex* v = it->second;
        v->setInspected(false);
    }
    
    forwardTraversal(stack_vertices);
    
    for (it = vertices.begin(); it != vertices.end(); it++)
    {
        vertex* v = it->second;
        
        int existingcount = 0;
        int groupNum = v->getGroup();
        if (groups.count(groupNum) !=0)
            existingcount = groups[groupNum];
        
        groups[groupNum] = existingcount + 1;
    }
    cout << "No. of SCC's: " << groups.size() << endl;
    
    set<int> groupsizes;
    for (map<int, int>::iterator it1 = groups.begin(); it1 != groups.end(); it1++)
    {
        int groupsize = it1->second;
        groupsizes.insert(groupsize);
    }

    cout << "Five largest SCC: ";
    set<int>::reverse_iterator it2 = groupsizes.rbegin();
    for (int i{0}; i < 5; i++)
    {
        cout << *it2 << ", ";
        it2++;
    }
    cout << endl;
    
    deleteVertices(vertices);
}

void initVertices(int nVertices, map<int, vertex*> &vertices)
{
    for(int i{0}; i < nVertices; i++)
    {
        vertices[i+1] = new vertex(i+1);
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
int readGraph(string filename, map<int, vertex*> &vertices)
{
    
    ifstream infile;        
    string line{""};
    
    infile.open(filename);
    if(!infile)
    {
        cerr << "Problem Opening File";
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);
    
    while(!infile.eof())
    {
        getline(infile,line);
        istringstream iss{line};  
        int firstvertex{};
        int secondvertex{};
     
        while (iss >> firstvertex >> secondvertex)
        {
            vertices[firstvertex]->addForwardConnection(vertices[secondvertex]);
            vertices[secondvertex]->addBackwardConnection(vertices[firstvertex]);
        }
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