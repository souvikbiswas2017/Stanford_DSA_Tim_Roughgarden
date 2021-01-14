#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int readData(string filename, vector<long> &values, vector<long> &weights, long &knapsackSize, long &nItems);
void initValues(vector<long> &x, long size, long value);
long max(long a, long b);
long getvalue(vector<long> v, long index);
long knapSack(long W, vector<long> wt, vector<long> val, long n);
void assign(vector<long> oldvec, vector<long> newvec);
int main()
{
    vector<long> weights;
    vector<long> values;
    long knapsackSize{};
    long nItems{};
    
    string filename{"../knapsack_big.txt"};
    readData(filename, values, weights, knapsackSize, nItems);
    cout<<knapsackSize<< " " << nItems << endl;
    cout << knapSack(knapsackSize,weights,values,nItems) << endl;
    
}

long knapSack(long W, vector<long> wt, vector<long> val, long n)
{
    vector<long> Kold;
    vector<long> Knew;
    initValues(Knew, W+1, 0);
    initValues(Kold, W+1, 0);
    for (int i{}; i <= n; i++)
    {
        Kold = Knew;
        cout << i << endl;
        for(int w{}; w <= W; w++)
        {
            
            if (w==0)
                Knew[w] = 0;
            else if (wt[i-1] <= w)
                Knew[w] = max(val[i-1] + Kold[w-wt[i-1]],  Kold[w]); 
            else
                Knew[w] = Kold[w];
        }
    }
    return Knew.at(W);  
    
}

int readData(string filename, vector<long> &values, vector<long> &weights, long &knapsackSize, long &nItems)
{
    ifstream infile;
    long weight{};
    long value{};
    
    infile.open(filename);
    if(!infile)

    {
        cout << "Problem opening file" << endl;
        return -1;
    }
    
    infile.clear();
    infile.seekg(0, ios::beg);
    
    infile >> knapsackSize >> nItems;
    while(infile >> value >> weight)
    {
        values.push_back(value);
        weights.push_back(weight);
    }
    return 0;
}

void initValues(vector<long> &x, long size, long value)
{
    for(int i{}; i <= size; i++)
    {
        x.push_back(value);
    }
}

long max(long a, long b)
{
    return (a > b)? a : b;
}