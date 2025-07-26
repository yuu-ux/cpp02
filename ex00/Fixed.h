#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &fixed);
  ~Fixed();
  int getRawBits(void) const;
  void setRawBits(int const raw);

 private:
  int fixed_point_num_;
  static const int fractional_bits_ = 8;
};

#endif
