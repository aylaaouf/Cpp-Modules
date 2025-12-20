#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    private:
        int _rawBits;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed(const int num);
        Fixed(const float num);
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        ~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);
bool Fixed::operator>(const Fixed& other) const;
bool Fixed::operator<(const Fixed& other) const;
bool Fixed::operator>=(const Fixed& other) const;
bool Fixed::operator<=(const Fixed& other) const;
bool Fixed::operator==(const Fixed& other) const;
bool Fixed::operator!=(const Fixed& other) const;
Fixed Fixed::operator+(const Fixed& other) const;
Fixed Fixed::operator-(const Fixed& other) const;
Fixed Fixed::operator*(const Fixed& other) const;
Fixed Fixed::operator/(const Fixed& other) const;

#endif