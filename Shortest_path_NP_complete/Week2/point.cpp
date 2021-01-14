#include "point.h"
#include <cmath>

point::point(int number, double x, double y): mNumber{number}, mX{x}, mY{y}
{
}

point::~point()
{
}

double point::distance(point* p)
{
    double sqr_dist = pow((this->X() - p->X()),2) + pow((this->Y()- p->Y()),2);
    return sqrt(sqr_dist);
}

