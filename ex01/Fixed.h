#ifndef FIXED_H
#define FIXED_H
#include <cmath>
#include <iostream>

class Fixed {
 public:
  Fixed();
  explicit Fixed(const int value);
  explicit Fixed(const float value);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();
  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

 private:
  int fixed_point_num_;
  static const int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed); // NOLINT

#endif
