#pragma once

class point
{
private:
    int mNumber;
    double mX;
    double mY;
public:
    point(int number, double x, double y);
    ~point();
    double distance(point* p);
    inline double X() { return mX; };
    inline double Y() { return mY; };
};

