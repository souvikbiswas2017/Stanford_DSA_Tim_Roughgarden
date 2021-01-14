#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "minheap.h"
#include "maxheap.h"

using namespace std;
int readIntegers(string filename, maxheap &low, minheap &high, vector<int> &median);
void insert(int number, maxheap &low, minheap &high);
int getmedian(maxheap &low, minheap &high);
int main()
{    
    vector<int> median;
    string filename{"../Median.txt"};
    maxheap low = maxheap{};
    minheap high = minheap{};
    readIntegers(filename,low,high,median);
    
    cout << median.size() << endl;
    long sum{};
    for(size_t i{}; i<median.size();i++)
    {
        sum += median.at(i);
    }
    cout << sum << endl;
    
    
    return 0;
}

int readIntegers(string filename, maxheap &low, minheap &high, vector<int> &median)
{
    ifstream infile;
    string line;
    int input{};
    infile.open(filename);
    if(!infile)
    {
        cout << "Problem opening file" << endl;
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);
    while(infile >> input)
    {
        insert(input, low, high);
        median.push_back(getmedian(low, high));
    }
    return 0;
}

void insert(int number, maxheap &low, minheap &high)
{
    if(low.heapsize() == 0 && high.heapsize()==0)
    {
        low.insert(number);
        return;
    }
    
    if (number <= low.getTop())
        low.insert(number);
    else if(number >= high.getTop())
        high.insert(number);
    else
        low.insert(number);
        
    if (low.heapsize()-high.heapsize()>1)
    {
        int top = low.getTop();
        low.deleteTop();
        high.insert(top);
    }
    else if(high.heapsize()-low.heapsize()>1)
    {
        int top = high.getTop();
        high.deleteTop();
        low.insert(top);
    }
}

int getmedian(maxheap &low, minheap &high)
{
    if (low.heapsize()> high.heapsize())
        return low.getTop();
    else if(low.heapsize() < high.heapsize())
        return high.getTop();
    else
        return low.getTop();
}