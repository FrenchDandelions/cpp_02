#include <iostream>

class Fixed
{
    private:
        int _val;
        static const int _bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed& operator= (const Fixed &fixed);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

