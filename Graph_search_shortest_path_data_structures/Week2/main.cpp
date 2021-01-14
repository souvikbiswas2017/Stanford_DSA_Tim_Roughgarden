#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "vertx.h"

using namespace std;
void initVertices(int nVertices, map<int, vertx*> &vertices);
int readWeightedGraph(string filename, vector<vertx*> &vertices);
void runBellmanFordEarlyTerminationAlgorithm(vector<vertx*> &vertices);
void runDijkstraAlgorithm(vector<vertx*> &vertices);
vertx* getVertex(vector<vertx*> &vertices, int vertxNumber);
bool isRemainingToProcess(vector<vertx*> &vertices);
int main()
{
    vector<vertx*> vertices;
    vector<int> printvertx {7,37,59,82,99,115,133,165,188,197};
    string filename{"../dijkstraData.txt"};
    readWeightedGraph(filename,vertices);
    runBellmanFordEarlyTerminationAlgorithm(vertices);
    
    for (size_t i=0; i < printvertx.size(); i++)
    {
        cout << getVertex(vertices, printvertx.at(i))->getMinDistance() << ',';
    }
    return 0;
    
    for (size_t i{0}; i < vertices.size(); i++)
        if (vertices[i])
            delete vertices[i];
    vertices.clear();
}

void initVertices(int nVertices, map<int, vertx*> &vertices)
{
    for(int i{0}; i < nVertices; i++)
        vertices[i+1] = new vertx(i+1);
}

int readWeightedGraph(string filename, vector<vertx*> &vertices)
{
    ifstream infile;
    string line;
    map<int, vertx*> genVertx;
    initVertices(200, genVertx);
    infile.open(filename);
    if(!infile)
    {
        cout << "Problem opening file" << endl;
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);

    while (!infile.eof())
    {
        getline(infile,line);
        
        istringstream iss{line};
        int vertxnum{}, convertxnum{}, weight{};
        iss >> vertxnum;
        if(vertxnum !=0)
        {
            vertx* v = genVertx[vertxnum];
            while(iss >> convertxnum)
            {
                iss.ignore(1,',');
                iss >> weight;
                
                vertx* convertx = genVertx[convertxnum];
                v->addWeight(convertx,weight);
            }
        }
    }
    
    for(auto pair : genVertx)
        vertices.push_back(pair.second);
    
    return 0;
}

void runBellmanFordEarlyTerminationAlgorithm(vector<vertx*> &vertices)
{
    vertx* first = getVertex(vertices,1);
    first->Process(0);
    int processed;
    do
    {
        processed=0;
        for(size_t i{}; i < vertices.size(); i++)
        {
            vertx* v = vertices.at(i);
            for(auto pair : v->getWeights())
            {
                if(v->getMinDistance() + pair.second < pair.first->getMinDistance())
                {
                    pair.first->Process(v->getMinDistance() + pair.second);
                    processed++;
                }
            }
        }
    } while(processed>0);
}

void runDijkstraAlgorithm(vector<vertx*> &vertices)
{
    vertx* selected = getVertex(vertices,1);
    selected->Process(0);
    while(isRemainingToProcess(vertices))
    {
        vector<vertx*> processed;
        for(vertx* v : vertices)
            if(v->getProcessed())
                processed.push_back(v);

        int greedyDijkstraScore{1000000};
        vertx* greedyDijkstraNode{nullptr};
        for(vertx* v : processed)
        {
            for(auto pair : v->getWeights())
            {
                if(!pair.first->getProcessed() && (v->getMinDistance() + pair.second < greedyDijkstraScore))
                {
                    greedyDijkstraScore = v->getMinDistance() + pair.second;
                    greedyDijkstraNode = pair.first;
                }
            }
        }
        if(greedyDijkstraNode)
            greedyDijkstraNode->Process(greedyDijkstraScore);
    } 
}


vertx* getVertex(vector<vertx*> &vertices, int vertxNumber)
{
    for(size_t i{0};i<vertices.size();i++)
    {
        if (vertices.at(i)->getVertxNumber()==vertxNumber)
            return vertices.at(i);
    }
    return nullptr;
}

bool isRemainingToProcess(vector<vertx*> &vertices)
{
    for (auto v : vertices)
        if (!v->getProcessed())
            return true;
    return false;
}