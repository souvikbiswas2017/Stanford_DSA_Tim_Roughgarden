#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "TSPpoint.h"

using namespace std;
int readPoints(string filename, vector<TSPpoint*> &points);
int clearPoints(vector<TSPpoint*> &points);
void calculateNearestPoints(vector<TSPpoint*> &points);
double getTSPcost(vector<TSPpoint*> &points);

int main()
{
    vector<TSPpoint*> points;
    string filename{"../nn.txt"};
    readPoints(filename, points);
    calculateNearestPoints(points);
    int counter = 0;
    for(size_t i = 0; i < points.size(); i++)
    {
        if(points[i]->alreadyANeighbor)
            counter++;
    }
    cout << "Number of Points : " << points.size() << endl;
    cout << "Number of Nieghboring Points : " << counter << endl;
    cout << "TSPcost " << (long)floor(getTSPcost(points)) << endl;
    clearPoints(points);
    return 0;
}

int readPoints(string filename, vector<TSPpoint*> &points)
{
    double x{0.0}, y{0.0};
    int nPoints{}, counter{};
    ifstream infile;
    infile.open(filename);
    if(!infile)
    {
        cout << "Problem opening file" << endl;
        return -1;
    }

    infile.clear();
    infile.seekg(0, ios::beg);
    
    infile >> nPoints;
    
    while (infile >> counter >> x >> y)
    {
        points.push_back(new TSPpoint(counter,x,y));
    }
    return 0;
}

int clearPoints(vector<TSPpoint*> &points)
{
    for (std::vector<TSPpoint*>::iterator it = points.begin(); it != points.end(); it++)
    {
        if (*it)
            delete (*it);
    }
    points.clear();
    return 0;
}

void calculateNearestPoints(vector<TSPpoint*> &points)
{
    TSPpoint* nextnode = points[0];
    bool foundNeighbor = true;
    while(foundNeighbor)
    {
        foundNeighbor = false;
        double minsqdist = 1e+40;
        int minidx = -1;
        for(size_t j{1}; j < points.size(); j++)
        {
            if(nextnode != points.at(j))
            {
                double sqdist = nextnode->SqDistance(points[j]);
                if (sqdist < minsqdist && !points[j]->alreadyANeighbor)
                {
                    minsqdist = sqdist;
                    minidx = j;
                }
            }
        }
        if (minidx != -1)
        {
            foundNeighbor = true;
            cout << "Neighbor : " << nextnode->getNumber() << " --> " << points[minidx]->getNumber() << endl;
            nextnode->setNearestPoint(points[minidx]);
            nextnode = points[minidx];
            nextnode->alreadyANeighbor = true;
        }
    }
}

double getTSPcost(vector<TSPpoint*> &points)
{
    double cost{0.0};
    
    TSPpoint* lastnode = points[0];
    while(lastnode->getNearestPoint() != nullptr)
    {
        cout << "My Number: " << lastnode->getNumber() << endl;
        cost += lastnode->getTSPedgecost();
        lastnode = lastnode->getNearestPoint();
    }
    
    cost += sqrt(lastnode->SqDistance(points[0]));
    return cost;
}
