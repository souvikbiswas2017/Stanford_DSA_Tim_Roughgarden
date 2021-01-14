#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include "edge.h"
#include "subtree.h"

using namespace std;
int readGraph(string filename, vector<edge*> &edges, set<int> &vertices);
bool edgeCompare(edge* a, edge* b);
void initSubTrees(vector<subtree*> &subtrees, const set<int> &vertices);
int find(const vector<subtree*> &subtrees, int v);
void unite(vector<subtree*> &subtrees, int v1, int v2);
int numberOfIndependentSubtrees(const vector<subtree*> &subtrees, const set<int> &vertices);
void kruskalMSTforClustering(vector<subtree*> &subtrees, vector<edge*> &edges, const set<int> &vertices);
int maxSpacingBetweenClusters(const vector<subtree*> &subtrees, const vector<edge*> &edges);
void printSubTrees(const vector<subtree*> &subtrees, const set<int> &vertices);
void printEdges(const vector<edge*> &edges);
void clear( vector<edge*> &edges, vector<subtree*> &subtrees);
int main()
{
    vector<edge*> edges;
    vector<subtree*> subtrees;
    set<int> vertices;
    string filename{"../clustering.txt"};
    readGraph(filename, edges, vertices);
    sort(edges.begin(), edges.end(), edgeCompare);
    //printEdges(edges);
    
    initSubTrees(subtrees, vertices);
    kruskalMSTforClustering(subtrees, edges, vertices);
    
    cout << "size of edges vector: " << edges.size() << endl;
    cout << "largest edge: " << (edges.at(edges.size()-1))->Length() << endl;
    cout << "number of subtrees: " << numberOfIndependentSubtrees(subtrees, vertices) << endl;
    //printSubTrees(subtrees, vertices);
    cout << "max spacing: " << maxSpacingBetweenClusters(subtrees, edges) << endl;
    clear(edges, subtrees);
    return 0;
}

int readGraph(string filename, vector<edge*> &edges, set<int> &vertices)
{
    ifstream infile;
    infile.open(filename);
    int nVertices;
    int v1{};
    int v2{};
    int length{};
    
    if(!infile)
    {
        cerr << "Problem Opening File";
        return -1;
    }
    infile.clear();
    infile.seekg(0, ios::beg);
    
    infile >> nVertices;
    cout << "number of vertices: " << nVertices << endl;
    while(infile >> v1 >> v2 >> length)
    {
        edge* e = new edge(v1, v2, length);
        edges.push_back(e);   

        vertices.insert(v1);
        vertices.insert(v2);
    }
    return 0;
}

bool edgeCompare(edge* a, edge* b)
{
    return (*a < *b) ;
}

void initSubTrees(vector<subtree*> &subtrees, const set<int> &vertices)
{
    for(int vertex : vertices)
    {
        subtrees.push_back(new subtree(vertex, 0));
    }
}

int find(const vector<subtree*> &subtrees, int v)
{
    while (subtrees.at(v-1)->getParent() != v)
    {
        v = subtrees.at(v-1)->getParent();
    }
    return subtrees.at(v-1)->getParent();
}

void unite(vector<subtree*> &subtrees, int v1, int v2)
{
    int v1root = find(subtrees, v1);
    int v2root = find(subtrees, v2);
    
    // Attach smaller rank tree under root of high  
    // rank tree (Union by Rank)
    if(subtrees.at(v1root-1)->getRank() < subtrees.at(v2root-1)->getRank())
        subtrees.at(v1root-1)->setParent(v2root);
    else if(subtrees.at(v1root-1)->getRank() > subtrees.at(v2root-1)->getRank())
        subtrees.at(v2root-1)->setParent(v1root);
    else
    {
        subtrees.at(v2root-1)->setParent(v1root);
        int v1rank =  subtrees.at(v1root-1)->getRank();
        subtrees.at(v1root-1)->setRank(++v1rank);    
    }
}

int numberOfIndependentSubtrees(const vector<subtree*> &subtrees, const set<int> &vertices)
{
    set<int> subtreeRoots;
    for(int v : vertices)
    {
        int root = find(subtrees, v);
        subtreeRoots.insert(root);
    }
    return subtreeRoots.size();
}

void kruskalMSTforClustering(vector<subtree*> &subtrees, vector<edge*> &edges, const set<int> &vertices)
{
    vector<edge*>::iterator it = edges.begin();
    while(numberOfIndependentSubtrees(subtrees, vertices) > 4)
    {
        int v1 = (*it)->V1();
        int v2 = (*it)->V2();
        //int root1 = find(subtrees, v1);
        //int root2 = find(subtrees, v2);
        unite(subtrees, v1, v2);
        it++;
        
        /*if (root1 != root2)
        {
            unite(subtrees, root1, root2);
            it++;
        }
        else
            it++;*/
    }
}

int maxSpacingBetweenClusters(const vector<subtree*> &subtrees, const vector<edge*> &edges)
{
    int maxspacing{1000000};
    for (edge* e : edges)
    {
        int root1 = find(subtrees, e->V1());
        int root2 = find(subtrees, e->V2());
        if (root1 != root2)
        {
            if (e->Length() < maxspacing)
                maxspacing = e->Length();
        }
    }
    return maxspacing;
}

void printEdges(const vector<edge*> &edges)
{
    for (edge* e : edges)
    {
        cout << "edges: " << e->V1() << " " << e->V2() << " " << e->Length() << endl;
    }
}

void printSubTrees(const vector<subtree*> &subtrees, const set<int> &vertices)
{
    set<int> subtreeRoots;
    for(int v : vertices)
    {
        int root = find(subtrees, v);
        subtreeRoots.insert(root);
    }
    
    for (int r : subtreeRoots)
    {
        cout << "subtree: " << r << " vertices: ";
        for (int v : vertices)
        {
            if (find(subtrees, v) == r)
            {
                cout << v << " ";
            }
        }
        cout << endl;
    }
}

void clear( vector<edge*> &edges, vector<subtree*> &subtrees)
{
   for (std::vector<edge*>::iterator it = edges.begin() ; it != edges.end(); ++it)
   {
     delete (*it);
   } 
   edges.clear();
   
   for (std::vector<subtree*>::iterator it = subtrees.begin() ; it != subtrees.end(); ++it)
   {
     delete (*it);
   } 
   subtrees.clear();
}
