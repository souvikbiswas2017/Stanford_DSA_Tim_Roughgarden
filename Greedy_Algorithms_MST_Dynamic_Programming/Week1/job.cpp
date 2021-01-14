#include "job.h"

job::job(double weight, double length) : mWeight{weight}, mLength{length}, mCompletionTime{}
{
}

job::~job()
{
}

bool job::operator<(const job &rhs)
{
#if OPTION == 0
    if(difference() < rhs.difference())
        return true;
    else if (difference() == rhs.difference() && getWeight() < rhs.getWeight())
        return true;
    return false;
#else
    if(ratio() < rhs.ratio())
        return true;
    return false;
#endif
}

bool job::operator==(const job &rhs)
{
    if(mWeight == rhs.getWeight() && mLength == rhs.getLength())
        return true;
    return false;
}

