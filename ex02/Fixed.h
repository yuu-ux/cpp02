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

  Fixed& operator--();
  Fixed& operator++();
  Fixed operator--(int);
  Fixed operator++(int);
  Fixed operator+(const Fixed&) const;
  Fixed operator-(const Fixed&) const;
  Fixed operator*(const Fixed&) const;
  Fixed operator/(const Fixed&) const;

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;
  static Fixed& min(Fixed& fixed1, Fixed& fixed2);
  static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
  static Fixed& max(Fixed& fixed1, Fixed& fixed2);
  static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

 private:
  int fixed_point_num_;
  static const int fractional_bits_ = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
bool operator>(const Fixed&, const Fixed&);
bool operator<(const Fixed&, const Fixed&);
bool operator<=(const Fixed&, const Fixed&);
bool operator>=(const Fixed&, const Fixed&);
bool operator==(const Fixed&, const Fixed&);
bool operator!=(const Fixed&, const Fixed&);

#endif
