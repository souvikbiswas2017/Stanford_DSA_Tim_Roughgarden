#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include "edge.h"

using namespace std;
void randomContraction(vector<int> &vertices, vector<edge> &edges, int iter);
int readGraph(string filename, vector<int> &vertices, vector<edge> &edges);
int main()
{
    string filename{"../kargerMinCut.txt"};
    vector<int> vertices;
    vector<edge> edges;
    readGraph(filename,vertices,edges);
    cout << "Number of vertices: " << vertices.size() << endl;
    cout << "Number of edges: " << edges.size() << endl;

    size_t mincut = 10000;
    for (int k{0};k < 200;k++)
    {
        vector<int> v2 = vertices;
        vector<edge> e2 = edges;
        cout << "Iter No.: " << k << " " << v2.size() << " " << e2.size() << endl;
        randomContraction(v2,e2,k);
        cout << "Mincut at Iter No.: " << k << " " << e2.size() << endl;
        if(e2.size() < mincut)
            mincut = e2.size();

    }
    cout << "Number of min cut: " << mincut << endl;
    
    return 0;
}

int readGraph(string filename, vector<int> &vertices, vector<edge> &edges)
{
    
    ifstream infile;        
    string line{""};
    int vertex{};
    int count{0};
    
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
        iss >> vertex;
        if(find(vertices.begin(), vertices.end(), vertex)==vertices.end())
            vertices.push_back(vertex);
        
        int adjacentvertex{};
        while (iss >> adjacentvertex)
        {
            count++;
            edge e{vertex,adjacentvertex};
            if(find(edges.begin(), edges.end(), e)==edges.end())
                edges.push_back(e);
        }
    }
    cout << "Number of edges in vertices: " << count << endl;
    infile.close();
    return 0;
}

void randomContraction(vector<int> &vertices, vector<edge> &edges, int iter)
{
    srand((int)iter);
    vector<int>::iterator it;
    while(vertices.size() > 2)
    {
        int rselect = (rand()%(edges.size()-1));
        edge e = *std::next(edges.begin(), rselect);
        
        int toBeDeleted = e.SecondVertex();
        int replaceBy = e.FirstVertex();
        vector<int> removeindexes;
        for (size_t i=0; i < edges.size(); i++)
        {
            if (edges.at(i).contains(toBeDeleted))
                edges.at(i).replaceVertex(toBeDeleted,replaceBy);
            if (edges.at(i).FirstVertex()==edges.at(i).SecondVertex())
                removeindexes.push_back(i);
        }
        
        for (int i=removeindexes.size()-1; i>=0; i--)
        {
            edges.erase(edges.begin()+removeindexes.at(i));
        }
        
        int tobeDeletedIndex = 0;
        for (size_t i=0; i < vertices.size(); i++)
        {
            if (vertices.at(i) == toBeDeleted)
            {
                tobeDeletedIndex = i;
                break;
            }
        }
        vertices.erase(vertices.begin()+tobeDeletedIndex);
    }
}