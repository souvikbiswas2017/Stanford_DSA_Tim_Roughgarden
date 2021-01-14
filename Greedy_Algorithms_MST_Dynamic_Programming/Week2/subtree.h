#pragma once

class subtree
{
private:
    int mParent;
    int mRank;
public:
    subtree(int parent, int rank);
    ~subtree();
    inline int getParent() { return mParent; };
    inline void setParent(int value) { mParent = value; };
    inline int getRank() { return mRank; };
    inline void setRank(int value) { mRank = value; };
};

