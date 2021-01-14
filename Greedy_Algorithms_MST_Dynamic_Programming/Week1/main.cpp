#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "job.h"

using namespace std;
int readJobs(string filename, vector<job*> &jobs);
void clearJobs(vector<job*> &jobs);
bool jobCompare(job* a, job* b);
int main()
{
    vector<job*> jobs;
    vector<job*>::iterator it;
    string filename{"../jobs.txt"};
    readJobs(filename,jobs);
    cout << "Size of array: " << jobs.size() << endl;
    sort(jobs.begin(),jobs.end(), jobCompare);
    reverse(jobs.begin(), jobs.end());
    
    /*for(size_t i{}; i < jobs.size(); i++)
    {
        cout << "weight/height: " << jobs[i]->getWeight() << "/" << jobs[i]->getLength() << endl;
    }*/
    
    long completiontime_i{};
    long sum_completion_time{};
    
    for(size_t i{}; i < jobs.size(); i++)
    {
        completiontime_i += jobs.at(i)->getLength();
        jobs.at(i)->setCompletionTime(completiontime_i);
        sum_completion_time += jobs.at(i)->getCompletionTime()*jobs.at(i)->getWeight();
    }
    cout << "Sum of completion time: " << sum_completion_time << endl;
    clearJobs(jobs);
    return 0;
}

int readJobs(string filename, vector<job*> &jobs)
{
    ifstream infile;
    int count;
    
    infile.open(filename);
    if(!infile)
    {
        cout << "Problem opening file" << endl;
        return -1;
    }
    infile.clear();
    infile.seekg(0,ios::beg);
    
    infile >> count;
    
    int weight;
    int length;
    while(infile >> weight >> length)
    {
        jobs.push_back(new job(weight,length));
    }
    return 0;
}

void clearJobs(vector<job*> &jobs)
{
    for(int i=jobs.size()-1; i >= 0; i--)
    {
        if (jobs[i])
            delete jobs[i];
    }
    jobs.clear();
}

bool jobCompare(job* a, job* b)
{
    return (*a < *b);
}