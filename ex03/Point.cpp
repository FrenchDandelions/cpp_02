#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float &x, const float &y): x(x), y(y)
{
    // std::cout << "Initializer constructor called" << std::endl;
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
    // std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &point){
    std::cout << "Copy assignement operator called" << std::endl;
    if(this != &point)
    {
        (const_cast<Fixed&>(this->x)) = point.x;
        (const_cast<Fixed&>(this->y)) = point.y;
    }
    return(*this);
}

const Fixed Point::getX(void) const
{
    return(this->x);
}

const Fixed Point::getY(void) const
{
    return(this->y);
}

Point::~Point()
{
    // std::cout << "Destructor called" << std::endl;
}
