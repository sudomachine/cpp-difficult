
#pragma once

#include <iostream>

struct PhoneNumber
{
  unsigned short countryCode;
  unsigned short cityCode;
  unsigned int number;
  int extensionNumber = -1;
  bool operator<(const PhoneNumber &phoneNumber);
  bool operator==(const PhoneNumber &phoneNumber);
  friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& phoneNumber);
};
