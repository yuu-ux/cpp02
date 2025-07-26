#include "Fixed.h"

Fixed::Fixed() : fixed_point_num_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy) {
  std::cout << "Copy constructor called" << std::endl;
  this->fixed_point_num_ = copy.getRawBits();
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
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_num_;
}

void Fixed::setRawBits(int const raw) {
  fixed_point_num_ = raw;
}
