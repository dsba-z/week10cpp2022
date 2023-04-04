#include "polarcoordinate.h"
#include <cmath>
#include <iostream>

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

std::pair<double, double> PolarCoordinate::convertToReal(const PolarCoordinate& polar)
{
    double x = polar._radius * cos(polar._angle);
    double y = polar._radius * sin(polar._angle);

    return std::make_pair(x, y);// {x,y}
}

PolarCoordinate PolarCoordinate::operator+(const PolarCoordinate& b) const
{
    std::pair<double, double> l = convertToReal(*this);
    std::pair<double, double> r = convertToReal(b);

    return convertToPolar(l.first + r.first, l.second + r.second);
}

PolarCoordinate PolarCoordinate::operator-(const PolarCoordinate& b) const
{
    std::pair<double, double> l = convertToReal(*this);
    std::pair<double, double> r = convertToReal(b);

    return convertToPolar(l.first - r.first, l.second - r.second);
}

PolarCoordinate& PolarCoordinate::operator+=(const PolarCoordinate& b)
{
    *this = *this + b;
    return *this;
}

PolarCoordinate& PolarCoordinate::operator-=(const PolarCoordinate& b)
{
    *this = *this - b;

    return *this;
}

PolarCoordinate PolarCoordinate::operator*(double b) const
{
    std::pair<double, double> l = convertToReal(*this);

    return convertToPolar(l.first * b, l.second * b);
}

PolarCoordinate PolarCoordinate::operator/(double b) const
{
    std::pair<double, double> l = convertToReal(*this);

    return convertToPolar(l.first / b, l.second / b);
}

 PolarCoordinate& PolarCoordinate::operator*=(double b)
 {
    *this = *this * b;

    return *this;
 }

 PolarCoordinate& PolarCoordinate::operator/=(double b)
 {
    std::pair<double, double> l = convertToReal(*this);
    PolarCoordinate res = convertToPolar(l.first / b, l.second / b);

    this->_radius = res._radius;
    this->_angle = res._angle;

    return *this;
 }