#ifndef POLARCOORDINATE_H
#define POLARCOORDINATE_H
#include <utility>
#include <cmath>

using PairXY = std::pair<double, double>;


class PolarCoordinate
{

public:
    PolarCoordinate(double radius, double angle);

    double getRadius() const { return _radius; }
    double getAngle() const { return _angle; }

    std::pair<double, double> toCartesian() const;

    static PolarCoordinate cartesianToPolar(double x, double y)
    {
        double radius = std::hypot(x, y);
        double angle = std::atan2(y, x);
        PolarCoordinate result(radius, angle);
        return result;
    }

    PolarCoordinate operator+(const PolarCoordinate& b) const;
    PolarCoordinate operator-(const PolarCoordinate& b) const;
    PolarCoordinate& operator+=(const PolarCoordinate& b);
    PolarCoordinate& operator-=(const PolarCoordinate& b);

    PolarCoordinate operator*(double b) const;
    PolarCoordinate operator/(double b) const;
    PolarCoordinate& operator*=(double b);
    PolarCoordinate& operator/=(double b);

private:
    double _radius;
    double _angle;
};



#endif// POLARCOORDINATE_H
