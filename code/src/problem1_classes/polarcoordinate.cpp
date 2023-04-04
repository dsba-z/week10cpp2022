#include "polarcoordinate.h"

#include <cmath>
#include <utility>

PolarCoordinate::PolarCoordinate(double radius, double angle) : _radius(radius), _angle(angle)
{
    counter++;
}


PolarCoordinate PolarCoordinate::convertToPolar(double x, double y)
{
    double rho = sqrt(pow(x, 2) + pow(y, 2));
    double theta = atan2(y, x);

    return PolarCoordinate(rho, theta);
}

std::pair<double, double> PolarCoordinate::polarToReal(const PolarCoordinate& polar)
{
    double x = polar._radius * cos(polar._angle);
    double y = polar._radius * sin(polar._angle);
    return std::make_pair(x, y);
}

PolarCoordinate PolarCoordinate::operator+(const PolarCoordinate& b) const
{
    return PolarCoordinate(_radius + b._radius, _angle + b._angle);
}

PolarCoordinate PolarCoordinate::operator-(const PolarCoordinate& b) const
{
    return PolarCoordinate(_radius - b._radius, _angle - b._angle);
}