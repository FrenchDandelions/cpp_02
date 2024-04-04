#include "Fixed.hpp"

Fixed::Fixed() : _val(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
    std::cout << "Copy assignement operator called" << std::endl;
    if(this != &fixed)
        this->_val = fixed.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_val);
}

void Fixed::setRawBits(int raw){
    this->_val = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
