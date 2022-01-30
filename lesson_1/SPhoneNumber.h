
#pragma once

#include <iostream>
#include <optional>

struct PhoneNumber
{
  int countryCode;
  int cityCode;
  int number;
  std::optional<int> extensionNumber;

  PhoneNumber(int countryCode,
	      int cityCode,
	      int number,
	      std::optional<int> extensionNumber = std::nullopt);
  bool operator<(const PhoneNumber& phoneNumber) const;
  bool operator==(const PhoneNumber& phoneNumber) const;
  PhoneNumber& operator=(const PhoneNumber& phoneNumber);
  friend std::ostream& operator<< (std::ostream& out, const PhoneNumber& phoneNumber);
};
