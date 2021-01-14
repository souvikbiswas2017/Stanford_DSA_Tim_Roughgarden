#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int readWeights(string filename, vector<long> &weights);
long maxlong(long a, long b);
int main()
{
    vector<long> weights;
    vector<long> A;
    string filename{"../mwis.txt"};
    readWeights(filename,weights);
    vector<bool> isincluded(weights.size(), false);
    vector<size_t> index{0,1,2,3,16,116,516,996};
    
        
    A.push_back(0);
    A.push_back(weights[0]);
    for(size_t i{2}; i < weights.size(); i++)
    {
        long maxval = maxlong(A.at(i-1), A.at(i-2)+weights.at(i-1));
        A.push_back(maxval);       
    }
    cout << A.size() << endl;
    
    size_t i{A.size()};
    while(i > 1)

    {
        cout << i << " " << weights.size() << endl;
        if(A.at(i-2)+weights.at(i-1) > A.at(i-1))
        {
            isincluded.at(i-1) = true;
            i -= 2;
        }
        else
            i--;
    }
    isincluded.at(0) = !isincluded.at(1);
    
    for (size_t i = 0; i < index.size(); i++)
    {
        if (index.at(i) < isincluded.size())
            cout << isincluded.at(index.at(i));
        else
            cout << false;
    }
    cout << endl;
 
}

int readWeights(string filename, vector<long> &weights)
{
    ifstream infile;
    string line;
    infile.open(filename);
    int nWeight{};
    long weight;
    if(!infile)
    {
        cout << "Problem opening file" << endl;
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);
    
    infile >> nWeight;
    while (infile >> weight)
    {
        weights.push_back(weight);
    }
    
    return 0;
}

long maxlong(long a, long b)
{
    return (a > b)? a : b;
}