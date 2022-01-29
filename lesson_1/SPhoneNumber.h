
#pragma once

#include <iostream>

struct PhoneNumber
{
  int countryCode;
  int cityCode;
  int number;
  int extensionNumber;

  PhoneNumber(int countryCode,
	      int cityCode,
	      int number,
	      int extensionNumber = -1);
  bool operator<(const PhoneNumber& phoneNumber) const;
  bool operator==(const PhoneNumber& phoneNumber) const;
  PhoneNumber& operator=(const PhoneNumber& phoneNumber);
  friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& phoneNumber);
};
