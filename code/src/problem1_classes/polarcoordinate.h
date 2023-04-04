#ifndef POLARCOORDINATE_H
#define POLARCOORDINATE_H

#include <utility>

class PolarCoordinate
{
public:
    PolarCoordinate(double radius, double angle);

    double getRadius() const { return _radius; }
    double getAngle() const { return _angle; }

    static PolarCoordinate convertToPolar(double x, double y);
    static std::pair<double, double> convertToReal(const PolarCoordinate& polar);

    PolarCoordinate operator+(const PolarCoordinate& b) const;
    PolarCoordinate operator-(const PolarCoordinate& b) const;
    PolarCoordinate& operator+=(const PolarCoordinate& b);
    PolarCoordinate& operator-=(const PolarCoordinate& b);

    PolarCoordinate operator*(double b) const;
    PolarCoordinate operator/(double b) const;
    PolarCoordinate& operator*=(double b);
    PolarCoordinate& operator/=(double b);

public:
    static int counter;

private:
    double _radius;
    double _angle;
};

#endif// POLARCOORDINATE_H
