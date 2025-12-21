#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) { _rawBits = other.getRawBits(); }
    return (*this);
}

Fixed::Fixed(const int num) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(num * (1 << _fractionalBits));
}

int Fixed::getRawBits( void ) const {
    return (_rawBits);
}

void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

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