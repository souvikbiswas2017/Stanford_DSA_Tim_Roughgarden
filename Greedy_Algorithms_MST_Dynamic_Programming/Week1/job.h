#pragma once
#define OPTION 1
class job
{
private:
    double mWeight;
    double mLength;
    double mCompletionTime;
public:
    job(double weight, double length);
    ~job();
    inline double getLength() const { return mLength; };
    inline double getWeight() const { return mWeight; };
    inline double getCompletionTime() const { return mCompletionTime; };
    inline void setCompletionTime(double value){ mCompletionTime = value; };
    inline double difference() const { return double(mWeight - mLength); };
    inline double ratio() const { return double(mWeight / mLength); };
    bool operator==(const job & rhs);
    bool operator<(const job & rhs);
};

