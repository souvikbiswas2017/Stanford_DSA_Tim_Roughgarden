#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;
int readIntegers(string filename, unordered_set<long> &s);
int main()
{
    unordered_set<long> s;
    unordered_set<long>::iterator it;
    string filename{"../prob-2sum.txt"};
    readIntegers(filename,s);
    
    long totalcount = 0;
    long sbegin = -10000;
    long send = 10000;
    for(long target{sbegin}; target <=send; target++ )
    {
        long targetcount{};
        for(it=s.begin(); it != s.end(); it++)
        {
            long seek = target - *it;
            if(s.find(seek)!=s.end())
                targetcount++;
        }
        cout << (targetcount/2) << " mataches for target :" << target <<  endl;
        if (targetcount > 0)
            totalcount++;
    }

    cout << "count: " << totalcount << endl;
    return 0;
}

int readIntegers(string filename, unordered_set<long> &s)
{
    ifstream infile;
    long number{};
    infile.open(filename);
    if(!infile)
    {
        cout << "Problem opening the file" << endl;
        return -1;
    }
    infile.clear();
    infile.seekg(0,ios::beg);
    
    while(infile >> number)
    {
        s.insert(number);
    }
    cout << "Number of uniques" << s.size() << endl;
    return 0;
}