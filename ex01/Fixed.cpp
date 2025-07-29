#include "Fixed.h"

Fixed::Fixed() : fixed_point_num_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : fixed_point_num_(value * (1 << fractional_bits_)) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : fixed_point_num_(static_cast<int>(roundf(value * (1 << fractional_bits_)))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) : fixed_point_num_(copy.getRawBits()) {
  std::cout << "Copy constructor called" << std::endl;
  *this = copy;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) {
    this->fixed_point_num_ = fixed.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

