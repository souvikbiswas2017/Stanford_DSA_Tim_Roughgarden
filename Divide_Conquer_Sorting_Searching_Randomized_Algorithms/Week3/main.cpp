#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int min(vector<int> &v);
int max(vector<int> &v);
int readfileintovector(string filename, vector<int> &v);
void quickSort(vector<int> &v, int low, int high, int &comparisonCount);
int choosePivot(vector<int> &v, int low, int high, int mode = 0);
void swap(vector<int> &v, int i, int j);

int main()        
{
    string filename{"../QuickSort.txt"};
    vector<int> v{};
    int retval{};
    retval = readfileintovector(filename,v);
    
    
    
    cout << retval << " : " << v.size() << endl;
    cout << "1st Element : "  << v.at(0) << endl;
    cout << "Last Element : "  << v.at(v.size()-1) << endl;
    cout << "MAX : " << max(v) << endl;
    cout << "MIN : " << min(v) << endl;
    int compCount{0};
    quickSort(v,0,v.size()-1,compCount);
    cout << "#Comp : " << compCount << endl;
    return 0;

}

int max(vector<int> &v)
{
    int maxval{0};
    for (size_t i{0}; i<v.size(); i++)
    {
        if(v.at(i) > maxval)
            maxval = v.at(i);
    }
    return maxval;
}

int min(vector<int> &v)
{
    int minval{10000000};
    for (size_t i{0}; i<v.size(); i++)
    {
        if(v.at(i) < minval)
            minval = v.at(i);
    }
    return minval;
}

int readfileintovector(string filename, vector<int> &v)
{
    ifstream infile;        
    int input{-32767};
    
    infile.open(filename);
    if(!infile)
    {
        cerr << "Problem Opening File";
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);
    
    while(infile >> input)
    {
        v.push_back(input);
    }
    infile.close();
    return 0;
}

void quickSort(vector<int> &v, int low, int high, int &compCount)
{
    if(low >= high)
        return;
    
    compCount += high-low;
    int pivot = choosePivot(v,low,high,3);
    int i{low+1};
    for (int j{low+1};j<=high;j++)
    {
        if(pivot > v.at(j))
        {
            swap(v,i,j);
            i++;
        }
    }
    swap(v,low,i-1);
    
    quickSort(v,low,i-2,compCount);
    quickSort(v,i,high,compCount);
    
        
    return;

}

int choosePivot(vector<int> &v, int low, int high, int mode)
{
    if (mode == 0)
        return v.at(low);
    else if(mode == 1)
    {
        swap(v, low, high);
        return v.at(low);
    }
    else if (mode == 2)
    {
        int mid = low+ floor((high-low)/2);
        int select{};
        if((v.at(mid) - v.at(low))*(v.at(mid) - v.at(high))<0)
            select = mid;
        else if((v.at(high) - v.at(low))*(v.at(high) - v.at(mid))<0)
            select = high;
        else
            select = low;
        swap(v,low,select);
        return v.at(low);
    }
    else
    {
        srand((int)time(0));
        int select = low + (rand()%(high-low));
        swap(v,low,select);
        return v.at(low);
    }
}

void swap(vector<int> &v, int i, int j)
{
    int temp = v.at(i);
    v.at(i) = v.at(j);
    v.at(j) = temp;
}