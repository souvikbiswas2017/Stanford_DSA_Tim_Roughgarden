#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <set>
#include <bitset>
#include <cmath>
#include <algorithm>
#include "point.h"

using namespace std;
int readPoints(string filename, vector<point*> &points);
int deletePoints(vector<point*> &points);
void buildDistanceTable(vector<vector<double>> &distance_table, const vector<point*> &points);
vector<bool> getSourceVector(int nSize);
void generateCombinations(vector<int> &combs, vector<bool> &source, int iStart, int k, int kSize);
vector<int> decodeCombination(int num);
int recodeCombination(int num, int skip);
double getMapData(unordered_map<int, unordered_map<int, double>> &mymap, int idx1, int idx2);
void setMapData(unordered_map<int, unordered_map<int, double>> &mymap, int idx1, int idx2, double value);
void movetonextiteration(unordered_map<int, unordered_map<int, double>> &currentmap, 
                         unordered_map<int, unordered_map<int, double>> &previousmap);
void TSPmain(vector<vector<double>> &dtable, vector<point*> points);
int getFullSet();
void printCombinations(const vector<int> &combs);
void printDistances(const vector<vector<double>> &distance_table);
const int M = 25;

int main()
{
    vector<point*> points;
    string filename{"../tsp.txt"};
    readPoints(filename,points);
    cout << "Number of Points : " << points.size() << endl;
    
    vector<vector<double>> distance_table;
    buildDistanceTable(distance_table, points);
    TSPmain(distance_table, points);

    /*vector<int> combinations{};
    vector<bool>src = getSourceVector(points.size());
    generateCombinations(combinations, src, 1, 1, 12);
    printCombinations(combinations);
    printDistances(distance_table);*/
    deletePoints(points);
    return 0;
}
        
int readPoints(string filename, vector<point*> &points)
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
    
    while (infile >> x >> y)
    {
        counter++;
        points.push_back(new point(counter,x,y));
    }
    return 0;
}
int deletePoints(vector<point*> &points)
{
    for (std::vector<point*>::iterator it = points.begin(); it != points.end(); it++)
    {
        if (*it)
            delete (*it);
    }
    points.clear();
    return 0;
}
void buildDistanceTable(vector<vector<double>> &distance_table, const vector<point*> &points)
{
    for (size_t i{0}; i < points.size(); i++)
    {
        vector<double> temp;
        for (size_t j{0}; j < points.size(); j++)
        {
            temp.push_back(points.at(i)->distance(points.at(j)));
        }
        distance_table.push_back(temp);
        temp.clear();
    }
}

vector<bool> getSourceVector(int nSize)
{
    vector<bool> src{};
    for(size_t i{}; i < (size_t)nSize; i++)
    {        
        src.push_back(false);
    }
    src.at(0) = true;
    return src;
}
void generateCombinations(vector<int> &combs, vector<bool> &source, int iStart, int k, int kSize)
{
    if (k == kSize)
    {
        bitset<M> bits;
        for(size_t i{0}; i < source.size(); i++)
            if(source.at(i))
                bits.set(i);
        combs.push_back((int)bits.to_ulong());
        return;
    }
    //no more item to checktru
    //return from here
    if (iStart == (int)source.size())
        return;
    
    source.at(iStart) = true;
    generateCombinations(combs, source, iStart + 1, k + 1, kSize);
    source.at(iStart) = false;
    generateCombinations(combs, source, iStart + 1, k, kSize);
    return;
}


void TSPmain(vector<vector<double>> &dtable, vector<point*> points)
{
    unordered_map<int, unordered_map<int, double>> currentmap;
    unordered_map<int, unordered_map<int, double>> previousmap;
    currentmap[1][0] = 0.0;
    
    for (size_t m = 1; m < points.size(); m++)
    {   
        cout << m << endl;
        movetonextiteration(currentmap, previousmap);

        vector<int> combinations{};
        vector<bool>src = getSourceVector(points.size());
        generateCombinations(combinations, src, 1, 1, m+1);
        for (int S : combinations)
        {
            vector<int> vS = decodeCombination(S);
            for (int j : vS)
            {
                double minSj;
                if (j != 0)
                {
                    minSj = 1e+20;
                    for (int k : vS)
                    {
                        if (k != j)
                        {
                            int S_skip_j = recodeCombination(S , j);
                            double calc_val = getMapData(previousmap, S_skip_j, k) + dtable.at(j).at(k);
                            if (minSj > calc_val)
                                minSj = calc_val;
                        }
                    }
                    setMapData(currentmap,S,j, minSj);
                }
           }
            
        }
    }
    
    int fullset = getFullSet();
    unordered_map<int, double> A_j = currentmap[fullset];
    double TSP{1e+20};
    for (pair<int, double> p : A_j)
    {
        if (p.first !=0)
        {
            if (TSP > (p.second + dtable.at(p.first).at(0)))
            {
                TSP = p.second + dtable.at(p.first).at(0);
            }
        }
    }
    cout << "TSP: " << floor(TSP) << endl;
    
}

double getMapData(unordered_map<int, unordered_map<int, double>> &mymap, int idx1, int idx2)
{
    if(idx1 != 1 && idx2 == 0)
        return 1e+20;
    return mymap[idx1][idx2];
}

void setMapData(unordered_map<int, unordered_map<int, double>> &mymap, int idx1, int idx2, double value)
{
    mymap[idx1][idx2] = value;
}

void movetonextiteration(unordered_map<int, unordered_map<int, double>> &currentmap, 
                         unordered_map<int, unordered_map<int, double>> &previousmap)
{
    previousmap.clear();
    previousmap = currentmap;
    currentmap.clear();
}

vector<int> decodeCombination(int num)
{
    vector<int> retval;
    bitset<M> bits(num);
    for (size_t i{0}; i < bits.size(); i++)
        if(bits.test(i))
            retval.push_back(i);
    return retval;
}

int recodeCombination(int num, int skip)
{
    bitset<M> bits(num);
    if (skip != -1)
        bits.reset(skip);
    return (int)bits.to_ulong();
}

int getFullSet()
{
    bitset<M> bits;
    bits.set();
    return (int)bits.to_ulong();
}

void printCombinations(const vector<int> &combs)
{
    for (int i : combs)
    {
        bitset<M> bits(i);
        for (size_t i{0}; i < bits.size(); i++)
            if(bits.test(i))
                cout << i+1 << " ";
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "Number of Combination: " << combs.size() << endl;
}

void printDistances(const vector<vector<double>> &distance_table)
{
    for (auto row : distance_table)
    {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << endl;
    }
}
