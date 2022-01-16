#include "SPerson.h"
#include "SPhoneNumber.h"
#include <iostream>

int main()
{
  /*
  // test
  Person p;
  p.firstName = "Sudakov";
  p.secondName = "Andrey";
  p.thirdName = "Alekseevich";

  Person p2;
  p2.firstName = "Sudakov";
  p2.secondName = "Andrey";
  p2.thirdName = "Alekseevich";

  std::cout << "What name is bigger?" << std::endl;
  p.printPersonData();
  std::cout << "OR" << std::endl;
  p2.printPersonData();

  std::cout << "p < p2: " << ((p < p2) ? "TRUE" : "FALSE") << std::endl;
  std::cout << "p == p2: " << ((p == p2) ? "TRUE" : "FALSE") << std::endl;
  */

  // TEST
  PhoneNumber number;
  number.countryCode = 7;
  number.cityCode = 981;
  number.number = 7947513;

  number.printPhoneNumber();

  PhoneNumber number2;
  number2.countryCode = 7;
  number2.cityCode = 981;
  number2.number = 7947513;

  number2.printPhoneNumber();

  std::cout << (number < number2) << std::endl;
  
  return 0;
}
