#include "Fixed.hpp"

/*Fixed points*/

Fixed::Fixed() : _val(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _val)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_val = _val << _bits_int;
}

Fixed::Fixed(const float _val)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_val = roundf(_val * (1 << _bits_int));
}

int Fixed::toInt(void) const {
    return(this->_val >> this->_bits_int);
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(_val) / (1 << this->_bits_int));

}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    this->operator=(copy);
}

Fixed& Fixed::operator= (const Fixed& fixed)
{
    // std::cout << "Copy assignement operator called" << std::endl;
    if(this != &fixed)
        this->_val = fixed.getRawBits();
    return(*this);
}

int Fixed::getRawBits(void) const{
    return(this->_val);
}

void Fixed::setRawBits(int raw){
    this->_val = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
    out << fixed.toFloat();
    return(out);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

/*Increment / decrement opereators*/

Fixed& Fixed::operator++(void)
{
    ++this->_val;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++this->_val;
    return(tmp);
}

Fixed& Fixed::operator--(void)
{
    --this->_val;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --this->_val;
    return(tmp);
}

/*Overloads operators*/

bool Fixed::operator<(const Fixed& fixed) const{
    return (this->getRawBits() < fixed.getRawBits());
}
    
bool Fixed::operator>(const Fixed& fixed) const{
    return (this->getRawBits() > fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed& fixed) const{
    return (this->getRawBits() <= fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed& fixed) const{
    return (this->getRawBits() >= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed& fixed) const{
    return (this->getRawBits() == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed& fixed) const{
    return (this->getRawBits() != fixed.getRawBits());
}

/*Min and Max*/

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
    return(a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b){
    return(a.getRawBits() > b.getRawBits() ? a : b);
}
    
const Fixed& Fixed::min(const Fixed &a, const Fixed &b){
    return(a.getRawBits() < b.getRawBits() ? a : b);
}
    
Fixed& Fixed::min(Fixed &a, Fixed &b){
    return(a.getRawBits() < b.getRawBits() ? a : b);
}


/*Simple operators overloads*/

Fixed Fixed::operator+(const Fixed &fixed){
    Fixed result(this->_val + fixed.getRawBits());
    return(result);
}

Fixed Fixed::operator-(const Fixed &fixed){
    Fixed result(this->_val - fixed.getRawBits());
    return(result);
}

Fixed Fixed::operator*(const Fixed &fixed){
    Fixed result;
    result.setRawBits((this->_val * fixed.getRawBits()) >> this->_bits_int);
    return(result);
}

Fixed Fixed::operator/(const Fixed &fixed){
    Fixed result((this->_val << this->_bits_int) / fixed.getRawBits());
    return(result);
}
