#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

int readfileintovector(string filename, vector<int> &v);
long long bruteForceInversionCount(vector<int> &v);
void mergeSortInversionCount(vector<int> &v, long long &invCount, int low, int high);
int min(vector<int> &v);
int max(vector<int> &v);

int main()
{
    string filename{"../IntegerArray.txt"};
    vector<int> v{};
    vector<int> sorted_v{};
    int retval{};
    retval = readfileintovector(filename,v);
    
    
    
    cout << retval << " : " << v.size() << endl;
    cout << "1st Element : "  << v.at(0) << endl;
    cout << "Last Element : "  << v.at(v.size()-1) << endl;
    cout << "MAX : " << max(v) << endl;
    cout << "MIN : " << min(v) << endl;
    
    long long invCount{0};
    mergeSortInversionCount(v,invCount,0,v.size()-1);
    cout << "#inversions : " << invCount << endl;
    
    cout << "#inversions by brute force: " << bruteForceInversionCount(v) << endl;
    return 0;

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

long long bruteForceInversionCount(vector<int> &v)
{
    long long invCount{0};
    for (size_t i{0}; i<v.size(); i++)
    {
        //cout << i << endl;
        for (size_t j{i+1}; j < v.size(); j++)
        {
            if(v.at(i) > v.at(j))
                invCount++;
        }
    }
    return invCount;
}

void mergeSortInversionCount(vector<int> &v, long long &invCount, int low, int high)
{
    //print low & high
    //cout << low << " " << high << endl;
    //base case handling
    if(low == high)
        return;
    
    int mid = floor((low+high)/2);
    
    mergeSortInversionCount(v,invCount,low, mid);
    mergeSortInversionCount(v,invCount,mid+1,high);
    
    vector<int> merged{};
    int i{low},j{mid+1};
    while(i <= mid && j <= high)
    {
        if (v.at(i) <= v.at(j))
        {
            merged.push_back(v.at(i));
            i++;
        }
        else
        {
            merged.push_back(v.at(j));
            invCount += (mid+1-i);
            j++;
        }
    }
    while(i<=mid)
        merged.push_back(v.at(i++));
    while(j<=high)
        merged.push_back(v.at(j++));
    
    for (int k{low},i{0};k<=high;k++,i++)
    {
        v.at(k) = merged.at(i);
    }
        
    return;

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