#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _val;
        static const int _bits_int = 8;

    public:
        Fixed();
        Fixed(const int _val);
        Fixed(const float _val);
        Fixed(const Fixed &copy);
        Fixed& operator=(const Fixed &fixed);
        Fixed operator+(const Fixed &fixed);
        Fixed operator-(const Fixed &fixed);
        Fixed operator*(const Fixed &fixed);
        Fixed operator/(const Fixed &fixed);

        bool operator<(const Fixed& fixed) const;
        bool operator>(const Fixed& fixed) const;
        bool operator<=(const Fixed& fixed) const;
        bool operator>=(const Fixed& fixed) const;
        bool operator==(const Fixed& fixed) const;
        bool operator!=(const Fixed& fixed) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);

        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

