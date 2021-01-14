#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int readGraph(string filename, vector<int> &indexI, vector<int> &indexJ,vector<int> &distance);
int min(int a, int b);
int main()
{
    const int LARGE = 100000000;
    vector<int> indexI;
    vector<int> indexJ;
    vector<int> distance;
    int N = 1000;
    int A[N][N];
    string filename{"../g3.txt"};
    readGraph(filename, indexI, indexJ, distance);
    
    for(int i{}; i < N; i++)
        for(int j{}; j < N; j++)
            A[i][j] = LARGE;
            
    for(int k{}; k < indexI.size(); k++)
        A[indexI.at(k)-1][indexJ.at(k)-1] = distance.at(k);
    
    for(int k{}; k < N; k++)
        for(int i{}; i < N; i++)
            for(int j{}; j < N; j++)
                A[i][j] = min(A[i][j], A[i][k]+A[k][j]);
    
    for(int i{}; i < N; i++)
    {
        if(A[i][i] < 0)
        {
            cout << "Found Negative Cycle" << endl;
            return -1;
        }
    }

    int minDist = LARGE;
    for(int i{}; i < N; i++)
        for(int j{}; j < N; j++)
            minDist = min(minDist, A[i][j]);
            
    cout << "Minimum Distance: " << minDist << endl;
    return 0;
}

int readGraph(string filename, vector<int> &indexI, vector<int> &indexJ,vector<int> &distance)
{
    ifstream infile;
    string line;
    infile.open(filename);
    if(!infile)
    {
        cout << "Problem opening file" << endl;
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);
    
    int nV, nE;
    int i, j ,dist;
    infile >> nV >> nE;
    while (infile>> i >> j >> dist)
    {
        indexI.push_back(i);
        indexJ.push_back(j);
        distance.push_back(dist);
    }
        
    return 0;
}

int min(int a, int b)
{
    return (a < b)? a : b;
}
