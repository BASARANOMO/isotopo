#include "point2d.h"

bool Point2D::operator<(const Point2D& pt) const {
    return x < pt.x || (x == pt.x && y < pt.y);
}


ostream& operator<<(ostream &os, const Point2D& pt) {
    return os << "(" << pt.x << "," << pt.y << ")";
}
