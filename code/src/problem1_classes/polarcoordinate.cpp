#include "polarcoordinate.h"

PolarCoordinate::PolarCoordinate(double radius, double angle)
: _radius(radius), _angle(angle)
{
}

PairXY PolarCoordinate::toCartesian() const
{
    double x = _radius * std::cos(_angle);
    double y = _radius * std::sin(_angle);
    PairXY result(x, y);
    return result;
}


PolarCoordinate PolarCoordinate::operator+(const PolarCoordinate& b) const
{
    // this b
    // this->x + b.x;
    
    PairXY thisXY = toCartesian();
    PairXY bXY = b.toCartesian();

    double resultX = thisXY.first + bXY.first;
    double resultY = thisXY.second + bXY.second;

    return cartesianToPolar(resultX, resultY);

}

PolarCoordinate PolarCoordinate::operator-(const PolarCoordinate& b) const
{
    // this b
    // this->x + b.x;
    PairXY thisXY = toCartesian();
    PairXY bXY = b.toCartesian();

    double resultX = thisXY.first - bXY.first;
    double resultY = thisXY.second - bXY.second;

    return cartesianToPolar(resultX, resultY);
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
    PolarCoordinate result = *this;
    result *= b;
    return result;
}


PolarCoordinate PolarCoordinate::operator/(double b) const
{
    PolarCoordinate result = *this;
    result /= b;
    return result;
}


PolarCoordinate& PolarCoordinate::operator*=(double b)
{
    _radius *= b;
    return *this;
}


PolarCoordinate& PolarCoordinate::operator/=(double b)
{
    _radius /= b;
    return *this;
}
