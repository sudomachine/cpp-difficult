
#include "SPhoneNumber.h"
#include <iostream>
#include <tuple>

std::ostream& operator<< (std::ostream& out, const PhoneNumber& phoneNumber)
{
  out << "+" << phoneNumber.countryCode \
      << "(" << phoneNumber.cityCode << ")" \
      << phoneNumber.number;
  if (phoneNumber.extensionNumber)
    out << " " << phoneNumber.extensionNumber;
  return out;
}

bool PhoneNumber::operator==(const PhoneNumber &number)
{
  return std::tie(this->countryCode,
		  this->cityCode,
		  this->number,
		  this->extensionNumber) ==
    std::tie(number.countryCode,
	     number.cityCode,
	     number.number,
	     number.extensionNumber);
  /*
  if (this->countryCode != number.countryCode ||
      this->cityCode != number.cityCode ||
      this->number != number.number ||
      this->extensionNumber != number.extensionNumber)
    return false;
  else
    return true;
  */
}

bool PhoneNumber::operator<(const PhoneNumber &number)
{
  return std::tie(this->countryCode,
		  this->cityCode,
		  this->number,
		  this->extensionNumber) <
    std::tie(number.countryCode,
	     number.cityCode,
	     number.number,
	     number.extensionNumber);
  /*
  // COUNTRY NUMBER COMPARISON
  if (this->countryCode < number.countryCode)
    return true;
  else if (this->countryCode > number.countryCode)
    return false;
  // CITY NUMBER COMPARISON
  if (this->cityCode < number.cityCode)
    return true;
  else if (this->cityCode > number.cityCode)
    return false;
  // NUMBER COMPARISON
  if (this->number < number.number)
    return true;
  else if (this->number > number.number)
    return false;
  // EXT NUMBER COMPARISON
  if (this->extensionNumber < number.extensionNumber)
    return true;
  else
    return false;
  */
}
