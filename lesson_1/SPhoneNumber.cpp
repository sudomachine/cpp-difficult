
#include "SPhoneNumber.h"
#include <iostream>
#include <tuple>

PhoneNumber::PhoneNumber(int countryCode,
			 int cityCode,
			 int number,
			 int extensionNumber)
{
  this->countryCode = countryCode;
  this->cityCode = cityCode;
  this->number = number;
  this->extensionNumber = extensionNumber;
}

std::ostream& operator<<(std::ostream& out, const PhoneNumber& phoneNumber)
{
  out << "+" << phoneNumber.countryCode \
      << "(" << phoneNumber.cityCode << ")" \
      << phoneNumber.number;
  if (phoneNumber.extensionNumber >= 0)
    out << " " << phoneNumber.extensionNumber;
  return out;
}

bool PhoneNumber::operator==(const PhoneNumber &number) const
{
  return std::tie(this->countryCode,
		  this->cityCode,
		  this->number,
		  this->extensionNumber) ==
    std::tie(number.countryCode,
	     number.cityCode,
	     number.number,
	     number.extensionNumber);
}

bool PhoneNumber::operator<(const PhoneNumber &number) const
{
  return std::tie(this->countryCode,
		  this->cityCode,
		  this->number,
		  this->extensionNumber) <
    std::tie(number.countryCode,
	     number.cityCode,
	     number.number,
	     number.extensionNumber);
}

PhoneNumber& PhoneNumber::operator=(const PhoneNumber& newPhoneNumber)
{
  this->countryCode = newPhoneNumber.countryCode;
  this->cityCode = newPhoneNumber.cityCode;
  this->number = newPhoneNumber.number;
  this->extensionNumber = newPhoneNumber.extensionNumber;
  return *this;
}
