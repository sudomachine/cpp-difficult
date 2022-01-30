
#include "SPerson.h"
#include "SPhoneNumber.h"
#include "CPhoneBook.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <tuple>

int main()
{ 
  std::ifstream file("fileForRead");
  PhoneBook book(file);
  std::cout << book << std::endl;

  std::cout << "------SortByPhone------" << std::endl;
  book.sortByPhone();
  std::cout << book << std::endl;

  std::cout << "------SortByName------" << std::endl;
  book.sortByName();
  std::cout << book << std::endl;

  std::cout << "------GetPhoneNumber------" << std::endl;
  auto printPhoneNumber = [&book](const std::string& secondName)
			  {
			    std::cout << secondName << " : ";
			    // std::optional<std::vector<PhoneNumber>> answer
			    auto answer = book.getPhoneNumber(secondName);
			    if (answer.has_value())
			      {
				if (answer.value().size() == 1)
				  {
				    std::cout << answer.value()[0] << std::endl;
				  }
				else
				  {
				    std::cout << "found more than 1" << std::endl;
				  }
			      }
			    else
			      {
				std::cout << "not found" << std::endl;
			      }
			  };

  printPhoneNumber("Sudakov");
  printPhoneNumber("Achmetov");
  printPhoneNumber("Ivanov");

  std::cout << "------changePhoneNumber------" << std::endl;
  book.changePhoneNumber(Person("Zemelis", "Olga", "Vyacheslavovna"),
			 PhoneNumber(7, 123, 15344458));
  book.changePhoneNumber(Person("Kovalev", "Denis", "Olegovich"),
			 PhoneNumber(16, 465, 9155448, 13));
  std::cout << book << std::endl;
  
}
