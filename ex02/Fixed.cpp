#include "Fixed.h"

Fixed::Fixed() : fixed_point_num_(0) {}

Fixed::Fixed(const int value) {
  fixed_point_num_ = value * (1 << fractional_bits_);
}

Fixed::Fixed(const float value) {
  fixed_point_num_ = static_cast<int>(roundf(value * (1 << fractional_bits_)));
}

Fixed::Fixed(const Fixed &copy) {
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  if (this != &fixed) {
    this->fixed_point_num_ = fixed.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
  return fixed_point_num_;
}

void Fixed::setRawBits(int const raw) {
  fixed_point_num_ = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(fixed_point_num_) / (1 << fractional_bits_);
}

int Fixed::toInt() const {
  return fixed_point_num_ / (1 << fractional_bits_);
}

Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2) {
    if (fixed1 <= fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 <= fixed2)
        return fixed1; // NOLINT
    return fixed2; // NOLINT
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2) {
    if (fixed1 >= fixed2)
        return fixed1;
    return fixed2;
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2) {
    if (fixed1 >= fixed2)
        return fixed1; // NOLINT
    return fixed2; // NOLINT
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    Fixed result;
    result.setRawBits(this->getRawBits() + fixed.getRawBits());
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    Fixed result;
    result.setRawBits(this->getRawBits() - fixed.getRawBits());
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    const int product = this->getRawBits() * fixed.getRawBits();
    Fixed result;
    result.setRawBits(product >> Fixed::fractional_bits_);
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    const int shifted = this->getRawBits() * (1 << Fixed::fractional_bits_);
    Fixed result;
    result.setRawBits(shifted / fixed.getRawBits());
    return result;
}

Fixed& Fixed::operator--() {
    --this->fixed_point_num_;
    return *this;
}

Fixed& Fixed::operator++() {
    ++this->fixed_point_num_;
    return *this;
}

Fixed Fixed::operator--(int) {
    const Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed Fixed::operator++(int) {
    const Fixed temp = *this;
    ++(*this);
    return temp;
}

bool operator<(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed1.getRawBits() < fixed2.getRawBits();
}

bool operator>(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed2 < fixed1;
}

bool operator<=(const Fixed &fixed1, const Fixed &fixed2) {
    return !(fixed2 < fixed1);
}

bool operator>=(const Fixed &fixed1, const Fixed &fixed2) {
    return !(fixed1 < fixed2);
}

bool operator==(const Fixed &fixed1, const Fixed &fixed2) {
    return !(fixed1 < fixed2) && !(fixed2 < fixed1);
}

bool operator!=(const Fixed &fixed1, const Fixed &fixed2) {
    return (fixed1 < fixed2) || (fixed2 < fixed1);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
