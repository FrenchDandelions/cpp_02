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
        Fixed& operator= (const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
