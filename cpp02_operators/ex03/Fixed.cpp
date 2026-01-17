#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) { }

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) { _rawBits = other.getRawBits(); }
    return (*this);
}

Fixed::Fixed(const int num) {
    _rawBits = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
    _rawBits = roundf(num * (1 << _fractionalBits));
}

int Fixed::getRawBits( void ) const {
    return (_rawBits);
}

void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

Fixed::~Fixed() { }

float Fixed::toFloat(void) const {
    return ((float)_rawBits / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
    return (_rawBits / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return (out);
}

bool Fixed::operator>(const Fixed& other) const {
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed& other) const {
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed& other) const {
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed& other) const {
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed& other) const {
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed& other) const {
    return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    _rawBits++;
    return (*this);
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _rawBits++;
    return (temp);
}

Fixed& Fixed::operator--() {
    _rawBits--;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _rawBits--;
    return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return (a);
    return (b);
}