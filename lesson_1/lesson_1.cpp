
#include "SPerson.h"
#include "SPhoneNumber.h"
#include "CPhoneBook.h"
#include <iostream>

int main()
{
  
  // test
  Person p;
  p.firstName = "Andrey";
  p.secondName = "Sudakov";

  Person p2;
  p2.firstName = "Andrey";
  p2.secondName = "Sudakov";
  p2.thirdName = "Alekseevich";

  std::cout << "What name is bigger?" << std::endl;
  std::cout << p << " OR " << p2 << std::endl;

  std::cout << "p < p2: " << ((p < p2) ? "TRUE" : "FALSE") << std::endl;
  std::cout << "p == p2: " << ((p == p2) ? "TRUE" : "FALSE") << std::endl;
  
  // TEST
  PhoneNumber number;
  number.countryCode = 7;
  number.cityCode = 981;
  number.number = 7947513;
  number.extensionNumber = 1;

  PhoneNumber number2;
  number2.countryCode = 7;
  number2.cityCode = 981;
  number2.number = 7947513;
  number2.extensionNumber = 1;

  std::cout << number << " and " << number2 << std::endl;

  std::cout << (number < number2) << std::endl;

  // test

  PhoneBook pb;

  return 0;
}
