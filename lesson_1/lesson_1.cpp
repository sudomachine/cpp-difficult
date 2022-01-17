
#include "SPerson.h"
#include "SPhoneNumber.h"
#include "CPhoneBook.h"
#include <iostream>

int main()
{
  
  // test
  Person p("Sudakov", "Andrey");
  std::cout << Person("Jhon", "Sinna") << std::endl;
  
  Person p2("Sudakov", "Andrey", "Alekseevich");

  std::cout << "What name is bigger?" << std::endl;
  std::cout << p << " OR " << p2 << std::endl;

  std::cout << "p < p2: " << ((p < p2) ? "TRUE" : "FALSE") << std::endl;
  std::cout << "p == p2: " << ((p == p2) ? "TRUE" : "FALSE") << std::endl;
  
  
  // TEST
  PhoneNumber number(7, 981, 7947513, 0);
  PhoneNumber number2(7, 981, 7947513, 1);

  std::cout << number << " and " << number2 << std::endl;

  std::cout << (number < number2) << std::endl;
  std::cout << (number == number2) << std::endl;
  
  // test

  //PhoneBook pb;

  return 0;
}
